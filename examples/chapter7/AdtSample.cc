#include <iostream>
using namespace std;


#define DEFAULT_FARE 10000

class Person
{
public:
    Person(){}
    virtual ~Person()
    {
        std::cout << "virtual ~Person()" << std::endl;
    }

    virtual void CalcFare() = 0;

    virtual unsigned int GetFare() const
    {
        return fare;
    }

protected:

    unsigned int fare = 0;

};

class Baby : public Person
{
public:
    virtual void CalcFare()
    {
        fare = 0;
    }
};

class Child : public Person
{
public:
    virtual void CalcFare()
    {
        fare = 0.5 * DEFAULT_FARE;
    }
};

class Teen : public Person
{
public:
    virtual void CalcFare()
    {
        fare = 0.75 * DEFAULT_FARE;
    }
};

class Adult : public Person
{
public:
    virtual void CalcFare()
    {
        fare = DEFAULT_FARE;
    }
};

int main(int argc, const char *argv[])
{
    Person *people[3] = { 0 };
    int age = 0;

    for(auto &person : people)
    {
        std::cout << "Enter your age please : ";
        std::cin >> age;

        if(age < 8)
        {
            person = new Baby;
        }

        else if (age < 14) 
        {
           person = new Child; 
        }

        else if (age < 20) 
        {
           person = new Teen; 
        }

        else 
        {
           person = new Adult; 
        }

        person->CalcFare();
    }

    for(auto person : people)
    {
        std::cout << person->GetFare() << "\\" << std::endl;
    }

    for(auto person : people)
    {
        delete person;
    }

    return 0;
}
