#include <iostream>
using namespace std;


class MyInterface
{
public:
    MyInterface()
    {
        std::cout << "MyInterface()" << std::endl;
    }

    virtual int GetData() const = 0;
    virtual void SetData(int param) = 0;
};

class MyData : public MyInterface
{
public:
    MyData()
    {
        std::cout << "MyData()" << std::endl;
    }

    virtual int GetData() const
    {
        return data;
    }

    virtual void SetData(int param)
    {
        data = param;
    }

private:
    int data = 0;
};

int main(int argc, const char *argv[])
{
    //MyInterface a;
    MyData b;
    b.SetData(5);

    std::cout << b.GetData() << std::endl;
    
    return 0;
}
