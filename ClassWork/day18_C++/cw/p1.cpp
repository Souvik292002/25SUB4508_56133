#include <iostream>
#include <string>

using namespace std;

/*
1. default cnstr
2. copy cnstr -> default copy constructor
3. paramterized cnstr

*/




class Student
{
    protected:
        int sem;
        string course;
    private:
        int phone;
        char gender;
        string id;
        string name;
        string address;
        string dob;
    public:
        Student() // default constructor
        {
            cout<<"Object got created"<<endl;
            //set default values
            name = "abc1";
            id = "0000";
            gender = 'O';
            phone = 111111;

        }
        //getters and setters 
        //1. individual
        //2. at a time
        //interfaces to the outside world
        int setValues(); 
        int setValuesArgs(string, string, char, int);
        void display(); 
        int setName(string);

};
/*
rdt_f ClassName::funcName() //:: -> scope resolution operator -> to access members outside the class
{
    //body of the function
}

*/

int Student::setValues()
{
    cout<<"\nEnter,"<<endl;
    cout<<"\nName: ";
    cin>>name;
    cout<<"\nID: ";
    cin>>id;
    cout<<"\nGender (M/F/O): ";
    cin>>gender;
    cout<<"\nPhno: ";
    cin>>phone;
    cout<<"\nThanks for providing the details\n"<<endl;
    return 0;
}

void Student::display()
{
    cout<<"\nStudent Details are\n"<<endl;
    cout<<"\nName: ";
    cout<<name;
    cout<<"\nID: ";
    cout<<id;
    cout<<"\nGender (M/F/O): ";
    cout<<gender;
    cout<<"\nPhno: ";
    cout<<phone;
    cout<<"\n=============================\n"<<endl;
}

int Student::setName(string nName)
{
    name = nName;
    return (EXIT_SUCCESS);
}

int Student::setValuesArgs(string n_Name, string n_id, char n_g, int n_phone)
{
    name = n_Name;
    id = n_id;
    gender = n_g;
    phone = n_phone;

    return (EXIT_SUCCESS);
}



int main()
{
    Student s1,s2;
    cout<<"Size of Student: "<<sizeof(Student)<<endl;
    cout<<"Size of Student: "<<sizeof(s1)<<endl;
    s1.display();
    s2.display();
    s1.setValues();
    s2.setValues();

    s1.display();
    s2.display();
    s1.setName("bhima");
    s1.display();

    Student s3;
    s3.setValuesArgs("shankar","103",'M',5555);
    s3.display();

    Student s4;

    s4.display();

    return 0;
}