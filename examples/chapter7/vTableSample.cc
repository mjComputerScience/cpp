#include <iostream>
using namespace std;

class MyData
{
public:
    MyData()
    {
        std::cout << "MyData()" << std::endl;
    }
    
    virtual ~MyData(){}
    virtual void testFunc1(){  } 
    virtual void testFunc2(){  } 
};


class MyDataEx : public MyData
{
public:
    MyDataEx()
    {
        std::cout << "MyDataEx()" << std::endl;
    }

    virtual ~MyDataEx(){}
    virtual void testFunc1(){  }
    virtual void testFunc2()
    {
        std::cout << "testFunc2()" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    MyData *pData = new MyDataEx;
    pData->testFunc2();
    delete pData;

    return 0;
}
