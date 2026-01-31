#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    // LOGICAL ERROR: loop condition should be i <= 5
    for (int i = 1; i < 5; i++) {
        sum += i;
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
