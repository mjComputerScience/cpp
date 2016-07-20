#include <iostream>

using namespace std;

class CMyData
{
public:
    // conversion constructor
    CMyData(int nParam) : m_nData(nParam)
    {
        std::cout << "CMyData(int)" << std::endl;
    }

    // copy constructor
    CMyData(const CMyData &rhs) : m_nData(rhs.m_nData)
    {
        std::cout << "CMyData(const CMyData &)" << std::endl;
    }
    
    // move sementic
    CMyData(const CMyData &&rhs) : m_nData(rhs.m_nData)
    {
        std::cout << "CMyData(const CMyData &&)" << std::endl;
    }

    // typecasting
    operator int()
    {
        return m_nData;
    }

    // + operator overloading
    CMyData operator+(const CMyData &rhs)
    {
        std::cout << "operator+" << std::endl;
        CMyData result(0);
        /* here, this is l-value of operator, rhs is r-value */
        std::cout << "this->m_nData :" << this->m_nData << std::endl;
        result.m_nData = this->m_nData + rhs.m_nData;

        return result;
    }

    CMyData &operator=(const CMyData &rhs)
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
