#include <iostream>

using namespace std;

class CMyDataA
{
public:
    CMyDataA()
    {
        std::cout << "CMyDataA()" << std::endl;
    }

    ~CMyDataA()
    {
        std::cout << "~CMyDataA()" << std::endl;
    }
};

class CMyDataB : public CMyDataA
{
public:
    CMyDataB()
    {
        std::cout << "CMyDataB()" << std::endl;
    }

    ~CMyDataB()
    {
        std::cout << "~CMyDataB()" << std::endl;
    }
};

class CMyDataC : public CMyDataB
{
public:
    CMyDataC()
    {
        std::cout << "CMyDataC()" << std::endl;
    }
    ~CMyDataC()
    {
        std::cout << "~CMyDataC()" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    std::cout << "**Begin**" << std::endl;
    CMyDataC data;
    std::cout << "**ENd**" << std::endl;
    return 0;
}
