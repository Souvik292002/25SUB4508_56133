#include <stdio.h>

#define LOG(msg) \
    printf("[LOG] File: %s | Function: %s | Line: %d | Message: %s\n", \
           __FILE__, __func__, __LINE__, msg)

void testFunction() {
    LOG("Inside testFunction");
}

int main() {
    printf("File: %s\n", __FILE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("Line: %d\n", __LINE__);

    LOG("Inside main");
    testFunction();

    return 0;
}
