#include <iostream>

using namespace std;

class CMyDataA
{
public:
    CMyDataA()
    {
        std::cout << "CMyDataA()" << std::endl;
        m_pszData = new char[32];
    }

    ~CMyDataA()
    {
        std::cout << "~CMyDataA()" << std::endl;
        delete[] m_pszData; 
    }
    
protected:
    char *m_pszData;
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
        delete[] m_pszData; // error here. do not delete inherited data
    }
};

int main(int argc, const char *argv[])
{
    std::cout << "**Begin**" << std::endl;
    CMyDataC data;
    std::cout << "**ENd**" << std::endl;
    return 0;
}
