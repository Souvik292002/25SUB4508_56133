#include "Client.h"

int main() {
    Client client("127.0.0.1", 4096);
    client.connectToEngine();
    return 0;
}
