#include <iostream>

using namespace std;

class CMyData
{
public:
    explicit CMyData(int nParam)
    {
        m_pnData = new int(nParam);
    }

    ~CMyData(){ delete m_pnData; }

    operator int(){ return *m_pnData; }

    CMyData &operator=(const CMyData &rhs)
    {
        if(this == &rhs)
            return *this;

        delete m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

    CMyData &operator+=(const CMyData &rhs)
    {
        int *pnNewData = new int(*m_pnData);

        *pnNewData += *rhs.m_pnData;

        delete m_pnData;
        m_pnData = pnNewData;

        return *this;
    }
 
private:
    /* data */

    int *m_pnData = nullptr;
};

int main(int argc, const char *argv[])
{
    CMyData a(0), b(5), c(10);
    a += b;
    a += c;
    std::cout << a << std::endl;

    return 0;
}
