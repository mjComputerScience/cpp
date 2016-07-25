#include <iostream>
using namespace std;


class MyData
{
public:
    MyData()
    {
        string = new char[32];
    }

    virtual ~MyData()
    {
        std::cout << "~MyData()" << std::endl;
        delete string;
    }

private:
    char *string;
};

class MyDataEx : public MyData
{
public:
    MyDataEx()
    {
        data = new int;
    }
    
    ~MyDataEx()
    {
        std::cout << "~MyDataEx()" << std::endl;
        delete data;
    }

private:
    int *data;
};

int main(int argc, const char *argv[])
{
    MyData *pData = new MyDataEx;

    delete pData;
    return 0;
}
