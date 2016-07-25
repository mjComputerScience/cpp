#include <iostream>

using namespace std;

class MyData
{
public:

    virtual void PrintData()
    {
        std::cout << "MyData: " << data << std::endl;
    }

    void testFunc()
    {
        std::cout << "testFunc() >> " << std::endl;
        //here, function PrintData is virtual function, so
        //it calls future redefined function PrintData
        PrintData();
    }

protected:

    int data = 10;
};

class MyDataEx : public MyData
{
public:
    using MyData::MyData;

    virtual void PrintData()
    {
        std::cout << "MyDataEx:" << data * 2 << std::endl;
    }
};


int main(int argc, const char *argv[])
{
    MyDataEx a;
    a.PrintData();

    MyData &b = a;
    b.PrintData();

    a.testFunc();
    return 0;
}
