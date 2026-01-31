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
        Student(Student&); // copy cnstr -> pass by ref
        Student(string, string, char, int);
        //getters and setters 
        //1. individual
        //2. at a time
        //interfaces to the outside world
        int setValues(); 
        int setValuesArgs(string, string, char, int);
        void display(); 
        int setName(string);
        ~Student();
        /*{
            cout<<"Destructor got invoked"<<endl;
        }*/

};
/*
rdt_f ClassName::funcName() //:: -> scope resolution operator -> to access members outside the class
{
    //body of the function
}

*/
Student::~Student()
{
    cout<<"Destructor got invoked"<<endl;
}
Student::Student(string n_name, string n_id, char n_g, int n_ph)
{
    cout<<"Parameterized cnstr got invoked"<<endl;
    name = n_name;
    id = n_id;
    gender = n_g;
    phone = n_ph;
}

Student::Student(Student &other)
{
    cout<<"Copy Cnstr got invoked"<<endl;
    
    name = other.name;
    id = "UID "+ other.id;
    gender = other.gender;
    phone = other.phone; 
}

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
    cout<<"\nS1 and s2"<<endl;
    Student s1,s2;
    
    s1.setValuesArgs("shankar","103",'M',5555);
    s1.display();
    cout<<"\nS3"<<endl;
    Student s3 = s1;
    s3.display();
    cout<<"\nS4"<<endl;
    Student s4(s1);
    s4.display();

    cout<<"\nS5"<<endl;
    
    Student s5("akash", "106", 'M', 4545);

    s5.display();
   

    return 0;
}