#include <iostream>
using namespace std;

namespace MathAdd {
    void operation() {
        cout << "Addition operation namespace" << endl;
    }
}

namespace MathMultiply {
    void operation() {
        cout << "Multiplication operation namespace" << endl;
    }
}

int main() {
    MathAdd::operation();
    MathMultiply::operation();
    return 0;
}
