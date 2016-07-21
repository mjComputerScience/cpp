#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData()
    {
        std::cout << "CMyData()" << std::endl;
    }

    //conversion constructor
    CMyData(int nParam)
    {
        std::cout << "CMyData(int)"<< std::endl;
    }

    //conversion constructor
    CMyData(double nParam)
    {
        std::cout << "CMyData(double)" << std::endl;
    }
};

class CMyDataEx : public CMyData
{
public:
    CMyDataEx()
    {
        std::cout << "CMyDataEx()" << std::endl;
    }

    CMyDataEx(int nParam) : CMyData(nParam)
    {
        std::cout << "CMyDataEx(int)" << std::endl;
    }

    CMyDataEx(double nParam) : CMyData()
    {
        std::cout << "CMyDataEx(double)" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    CMyData a;
    std::cout << "******" << std::endl;
    CMyDataEx b(5);
    std::cout << "******" << std::endl;
    CMyDataEx c(2.5);
    return 0;
}
