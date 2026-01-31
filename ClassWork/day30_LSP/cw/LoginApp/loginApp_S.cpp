#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdexcept>

#define PORT 9090
#define BUFFER 1024
#define DB_FILE "users.db"

// ---------------- Exception ----------------
class SocketException : public std::runtime_error {
public:
    explicit SocketException(const std::string& msg)
        : std::runtime_error(msg) {}
};

// ---------------- User ----------------
struct User {
    std::string username;
    std::string password;
    std::string role;
};

// ---------------- User Manager ----------------
class UserManager {
public:
    static std::vector<User> loadUsers() {
        std::vector<User> users;
        std::ifstream file(DB_FILE);

        if (!file) {
            std::ofstream out(DB_FILE);
            out << "admin,admin123,admin\n";
            out.close();
            file.open(DB_FILE);
        }

        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            User u;
            getline(ss, u.username, ',');
            getline(ss, u.password, ',');
            getline(ss, u.role);
            users.push_back(u);
        }
        return users;
    }

    static User authenticate(const std::string& u,
                             const std::string& p,
                             bool& ok) {
        auto users = loadUsers();
        for (auto& user : users) {
            if (user.username == u && user.password == p) {
                ok = true;
                return user;
            }
        }
        ok = false;
        return {};
    }

    static void addUser(const User& user) {
        std::ofstream file(DB_FILE, std::ios::app);
        file << user.username << ","
             << user.password << ","
             << user.role << "\n";
    }
};

// ---------------- Login Session ----------------
class LoginSession {
private:
    int fd;

    void sendLine(const std::string& msg) {
        std::string m = msg + "\n";
        write(fd, m.c_str(), m.size());
    }

    std::string recvLine() {
        char ch;
        std::string line;
        while (read(fd, &ch, 1) == 1) {
            if (ch == '\n') break;
            line += ch;
        }
        return line;
    }

    void adminMenu() {
        while (true) {
            sendLine("\n--- Admin Menu ---");
            sendLine("1. View Users");
            sendLine("2. Add User");
            sendLine("3. Logout");
            sendLine("Choice:");

            std::string ch = recvLine();

            if (ch == "1") {
                auto users = UserManager::loadUsers();
                for (auto& u : users)
                    sendLine(u.username + " (" + u.role + ")");
            } else if (ch == "2") {
                sendLine("Username:");
                std::string u = recvLine();
                sendLine("Password:");
                std::string p = recvLine();
                UserManager::addUser({u, p, "user"});
                sendLine("User added.");
            } else if (ch == "3") {
                break;
            }
        }
    }

    void userMenu(const User& user) {
        while (true) {
            sendLine("\n--- User Menu ---");
            sendLine("1. View Profile");
            sendLine("2. Logout");
            sendLine("Choice:");

            std::string ch = recvLine();
            if (ch == "1") {
                sendLine("Username: " + user.username);
                sendLine("Role: " + user.role);
            } else if (ch == "2") {
                break;
            }
        }
    }

public:
    explicit LoginSession(int client_fd) : fd(client_fd) {}

    void start() {
        sendLine("Username:");
        std::string uname = recvLine();
        sendLine("Password:");
        std::string pass = recvLine();

        bool ok;
        User user = UserManager::authenticate(uname, pass, ok);

        if (!ok) {
            sendLine("Invalid credentials.");
            return;
        }

        sendLine("Login successful.");

        if (user.role == "admin")
            adminMenu();
        else
            userMenu(user);
    }
};

// ---------------- TCP Fork Server ----------------
class TCPForkServer {
private:
    int server_fd;

public:
    TCPForkServer() {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0)
            throw SocketException("Socket failed");

        int opt = 1;
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(PORT);

        bind(server_fd, (sockaddr*)&addr, sizeof(addr));
        listen(server_fd, 10);

        signal(SIGCHLD, SIG_IGN);
    }

    void run() {
        std::cout << "Login Server running on port " << PORT << "\n";

        while (true) {
            int client_fd = accept(server_fd, nullptr, nullptr);
            if (client_fd < 0) continue;

            if (fork() == 0) {
                close(server_fd);
                LoginSession(client_fd).start();
                close(client_fd);
                _exit(0);
            }
            close(client_fd);
        }
    }
};

// ---------------- Main ----------------
int main() {
    try {
        TCPForkServer server;
        server.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}
