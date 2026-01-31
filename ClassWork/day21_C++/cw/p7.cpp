class Person
{

};

class Employee
{
    Person *p;
        Employee(){
            p = new Person();
        }
};

int main()
{
    
    Employee e;
}