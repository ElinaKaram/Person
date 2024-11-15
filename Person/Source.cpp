#include <iostream>
#include <string>
using namespace std;

class Person 
{
protected:

    const char* name;
    int age;

public:

    Person(const char* name, int age) : name(name), age(age) {}

    virtual void ShowInfo() const 
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person()
    {
        cout << "Person destructor called for " << name << endl;
    }
};

class Student : public Person
{
private:

    string university;

public:

    Student(const char* name, int age, const string& university): Person(name, age), university(university) {}

    void ShowInfo() const override 
    {
        Person::ShowInfo();
        cout << "University: " << university << endl;
    }

    ~Student() override 
    {
        cout << "Student destructor called for " << name << endl;
    }
};

class Worker : public Person 
{
private:

    double salary;
    int projects[5]; 

public:

    Worker(const char* name, int age, double salary): Person(name, age), salary(salary)
    {    
        for (int i = 0; i < 5; ++i) projects[i] = i + 1;
    }

    void ShowInfo() const override 
    {
        Person::ShowInfo();
        cout << "Salary: " << salary << ", Projects: ";

        for (int i = 0; i < 5; ++i) cout << projects[i] << " ";
        cout << endl;
    }

    ~Worker() override
    {
        cout << "Worker destructor called for " << name << endl;
    }
};

class Driver : public Person 
{
private:

    string carNumber;
    string licenseNumber;

public:

    Driver(const char* name, int age, const string& carNumber, const string& licenseNumber)
    : Person(name, age), carNumber(carNumber), licenseNumber(licenseNumber) {}

    void ShowInfo() const override 
    {
        Person::ShowInfo();
        cout << "Car Number: " << carNumber << ", License Number: " << licenseNumber << endl;
    }

    ~Driver() override 
    {
        cout << "Driver destructor called for " << name << endl;
    }
};

class Doctor : public Person 
{
private:

    string specialty;
    int yearsOfExperience;

public:

    Doctor(const char* name, int age, const string& specialty, int yearsOfExperience)
    : Person(name, age), specialty(specialty), yearsOfExperience(yearsOfExperience) {}

    void ShowInfo() const override
    {
        Person::ShowInfo();
        cout << "Specialty: " << specialty << ", Years of Experience: " << yearsOfExperience << endl;
    }

    ~Doctor() override 
    {
        cout << "Doctor destructor called for " << name << endl;
    }
};

int main()
{
    Person* people[4];

    people[0] = new Student("Joe", 22, "Harvard");
    people[1] = new Worker("Chloe", 28, 55000.5);
    people[2] = new Driver("David", 30, "ABC123", "D-84629");
    people[3] = new Doctor("Dr.Bernard", 37, "Cardiology", 13);

    for (int i = 0; i < 4; ++i) 
    {
        people[i]->ShowInfo();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) 
    {
        delete people[i];
    }

    return 0;
}