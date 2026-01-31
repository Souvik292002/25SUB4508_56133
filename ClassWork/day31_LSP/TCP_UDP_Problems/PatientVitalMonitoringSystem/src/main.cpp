#include <thread>
#include "state_manager.h"

void startVitalReceiver(StateManager&);
void startSnapshotServer(StateManager&);

int main() {
    StateManager stateManager;

    std::thread udpThread(startVitalReceiver, std::ref(stateManager));
    std::thread snapshotThread(startSnapshotServer, std::ref(stateManager));
    std::thread timeoutThread(&StateManager::monitorTimeouts, &stateManager);

    udpThread.join();
    snapshotThread.join();
    timeoutThread.join();

    return 0;
}
