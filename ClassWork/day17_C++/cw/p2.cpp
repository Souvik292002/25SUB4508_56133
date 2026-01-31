#include <iostream>
using namespace std;
/*
cmdpromt(argv[][])
{
    //count no of argv
    //update count of argc
    argc = 5;
    main(argc, *argv[])//of a process
}
*/

int main(int argc, char **argv)
{

    cout<<"No of args suppiled: "<<argc<<endl;
    /*cout<<"0th arg name: "<<argv[0]<<endl;
    cout<<"1 arg name: "<<argv[1]<<endl;
    cout<<"2 arg name: "<<argv[2]<<endl;
    */
    for(int i=0;i<argc;i++)
        cout<<"argv["<<i<<"] : "<<argv[i]<<endl;
     
    
    if(argc !=3)
    {
        cout<<"supply correct args"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Correct args"<<endl;


    cout<<"\n\n";
    return (EXIT_SUCCESS);
}