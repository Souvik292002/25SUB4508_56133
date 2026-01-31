/*
Def: An Allocator is an Obj which handles mem allocation and deallocation
    for stl containers

    stl does not directly use new or delete. they use allocators internally

1. Alloc custom mem strategies
2. Seperate mem management for DS.
3. improve performanance
4. Enable mem pooling, tracking, debugging

std::allocator<T>

internally they use functions like,
1. allocate() -> new
2. dellocate() -> delete
3. contruct() -> placement new
4. destroy() -> destructor call

vector <int> vec

vector, list, map, set, unordered_map.

Adaptors liks stack and queue use allocator -> indirectly


used, (custom allocator usages)
1. Game Engines
2. Emmbeded sys
3. Automotive/RTOS
4. Memory leak dectection



10 -> 100 BA - S-1, C-1
20-> 200, 204 -S-2, C-2
      10  20 , i need to free 100
30-> 300 304 308 312 - S3, C-4
      10 20  30, i need to free 200, 204

program is about to end, object created losses its scope, 300-312 need to freed(4)

str1 = 2000 -> 'g' 'e' 'e' 'k' 's'
str2 = 3000 -> "this is a cpp programming"
str3 = 4000

p -> str1 = 2000

p+1 -> str2 = 3000

map<unsigned long long int,char *> => string
map<2000, "geeks">
map<3000, "This is a cpp programming">

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyAllocator
{
public:
    using value_type = T;
    MyAllocator(){}
    template <class U>
    MyAllocator(const MyAllocator<U>&){}

    //Allocate mem
    T *allocate(size_t n)
    {
        cout<<"(Allocator) Allocating "<< n<<" Objects\n";
        return static_cast<T*>(::operator new(n*sizeof(T)));
    }

    void deallocate(T *p, size_t n)
    {
        cout<<"(Allocator) deallocating "<<n<<" Objects\n";
        ::operator delete(p);
    }


};


int main()
{
    vector <int, MyAllocator<int>> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);


    cout<<"\nVector Elements are\n";
    for(int x: vec)
        cout<<"\n"<<x<<endl;
    
        return 0;
}