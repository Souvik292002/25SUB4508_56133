#include <stdio.h>
#include "myheader.h"
#include "myheader.h"   // Included twice intentionally

void displayMessage() {
    printf("Header included only once!\n");
}

int main() {
    displayMessage();
    return 0;
}
