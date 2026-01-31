#include <stdio.h>

struct NormalStruct {
    char a;
    int b;
    char c;
};

#pragma pack(1)
struct PackedStruct {
    char a;
    int b;
    char c;
};
#pragma pack()

int main() {
    struct NormalStruct ns;
    struct PackedStruct ps;

    printf("Size of NormalStruct = %lu\n", sizeof(ns));
    printf("Size of PackedStruct = %lu\n", sizeof(ps));

    return 0;
}
