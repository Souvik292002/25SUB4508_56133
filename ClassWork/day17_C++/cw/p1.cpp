#include <iostream>
/*
namespace tag_name
{
    //variables
    //functions
    //classes

}


print() => =====================
print() => *********************
*/

namespace spandan{
    void print(char ch){
        std::cout<<"\n";
        for(int i=0;i<50;i++)
            std::cout<<ch;
        std::cout<<'\n';
    }
};


namespace varsha{
    void print(char ch){
        std::cout<<"\n";
        for(int i=0;i<50;i++)
            std::cout<<ch;
        std::cout<<'\n';
    }
}



int main(){
    spandan::print('=');
    std::cout<<"hello"<<std::endl;
    varsha::print('$');
    return 0;
}