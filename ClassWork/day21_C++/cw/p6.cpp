#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> owner = make_shared<int>(400);
    weak_ptr<int> observer = owner;
    cout << "shared_ptr reference count: " << owner.use_count() << endl;

    // Lock to use weak_ptr
    if (auto locked = observer.lock())
    {
        cout << "Object value: " << *locked << endl;
        *locked = 500;
    }
    *owner = 600;
    cout<<"\nValue: "<<*owner<<endl;
    owner.reset();
    
    cout << endl;

    return 0;
}