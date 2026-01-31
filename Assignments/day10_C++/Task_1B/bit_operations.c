#include <stdio.h>

/* Count set bits using while loop */
int countBits_while(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/* Count set bits using for loop */
int countBits_for(int n) {
    int count = 0;
    for (; n; n >>= 1) {
        count += n & 1;
    }
    return count;
}

/* Get specific bit (0 or 1) */
int getBit(int n, int pos) {
    return (n >> pos) & 1;
}

/* Set a specific bit */
int setBit(int n, int pos) {
    return n | (1 << pos);
}

/* Toggle a specific bit */
int toggleBit(int n, int pos) {
    return n ^ (1 << pos);
}

int main() {
    int num = 10;   // Binary: 1010
    int pos = 1;

    printf("Number: %d\n", num);
    printf("Count bits (while): %d\n", countBits_while(num));
    printf("Count bits (for): %d\n", countBits_for(num));
    printf("Bit at position %d: %d\n", pos, getBit(num, pos));
    printf("After setting bit %d: %d\n", pos, setBit(num, pos));
    printf("After toggling bit %d: %d\n", pos, toggleBit(num, pos));

    return 0;
}
