#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData(int nParam)
    {
        std::cout << "CMyData(int)" << std::endl;
        m_pnData = new int(nParam);
    };

    CMyData(const CMyData &rhs)
    {
        std::cout << "CMyData(const CMyData &)" << std::endl;
        m_pnData = new int(*rhs.m_pnData);
    }

    ~CMyData(){ delete m_pnData; }

    operator int() { return *m_pnData; }

    CMyData operator+(const CMyData &rhs)
    {
        return CMyData(*m_pnData + *rhs.m_pnData);
    }

    CMyData &operator=(const CMyData &rhs)
    {
        std::cout << "operator=" << std::endl;

        if(this == &rhs)
            return *this;

        delete m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

    CMyData &operator=(CMyData &&rhs)
    {
        std::cout << "operator = (move)" << std::endl;

        m_pnData = rhs.m_pnData;
        rhs.m_pnData = nullptr;

        return *this;
    }

private:
    /* data */

    int *m_pnData = nullptr;
};

int main(int argc, const char *argv[])
{
    CMyData a(0), b(3), c(4);
    std::cout << "** Before **" << std::endl;

    a = b + c;
    std::cout << "** after **" << std::endl;
    std::cout << a << std::endl;

    a = b;
    std::cout << a << std::endl;

    return 0;
}
