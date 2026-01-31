#include <iostream>
#include <string>

using namespace std;


class BC
{
    private:
        int bc_x;
    protected:
        int bc_y;
    public:
        BC()
        {
            cout<<"\ncnstr of BC got invoked\n";
            
            bc_x = 10;
            bc_y = 20;
            bc_z = 30;    
        }
        int bc_z;
        void get_bc_x()
        {
            cout<<bc_x<<endl;
        }
        ~BC()
        {
            cout<<"\ndestr of BC got invoked\n";
            
        }
};

class DC : private BC 
{
    private:
        int dc_x;
        //int bc_y; ->protected
        //int bc_z; - public
    protected:
        int dc_y;
        
    public:
        DC()
        {
            cout<<"\ncnstr of DC got invoked\n";
            dc_x = 40;
            dc_y = 50;
            dc_z = 60;    
        }
        
        int dc_z;
        void get_dc_x()
        {
            cout<<dc_x<<endl;
        }
        void disp_dc()
        {
            cout<<dc_x<<endl;
            cout<<bc_y<<endl;
            cout<<bc_z<<endl;
        }
        ~DC()
        {
            cout<<"\ndestr of DC got invoked\n";
            
        }
};
/*
class test: public DC
{
    public:
        test(){
            cout<<"\ncnstr of test got invoked\n";
        }
        void disp(){
            cout<<"\nt class - disp()\n";
            get_dc_x();
            cout<<dc_y<<endl;
            cout<<dc_z<<endl;
            get_bc_x();
            cout<<bc_y<<endl;
            cout<<bc_z<<endl;
            
        }
        ~test()
        {
            cout<<"\ndestr of test got invoked\n";
        }
};
*/

int main()
{
    DC d;
    d.disp_dc();
    return 0;
}

