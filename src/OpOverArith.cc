#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData(int nParam)
    {
        std::cout << "CMyData(int)" << std::endl;
    }

    CMyData(const CMyData &rhs)
    {
        std::cout << "CMyData(const CMyData &)" << std::endl;
    }

    CMyData(const CMyData &&rhs)
    {
        std::cout << "CMyData(const CMyData &&)" << std::endl;
    }

    operator int()
    {
        return m_nData;
    }

    CMyData operator+(const CMyData &rhs)
    {
        std::cout << "operator+" << std::endl;
        CMyData result(0);
        result.m_nData = this->m_nData + rhs.m_nData;

        return result;
    }

    CMyData &operator= (const CMyData &rhs)
    {
        std::cout << "operator=" << std::endl;
        m_nData = rhs.m_nData;

        return *this;
    }
    

private:
    /* data */

    int m_nData = 0;
};

int main(int argc, const char *argv[])
{
    std::cout << "** Begin **" << std::endl;
    CMyData a(0), b(3), c(4);

    a = b + c;
    std::cout << a << std::endl;
    std::cout << "** End **" << std::endl;
    

    return 0;
}
