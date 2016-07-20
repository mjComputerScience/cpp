#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData(int nParam) : m_nData(nParam) {}

    operator int() { return m_nData; }

    int operator++()
    {
        std::cout << "oeprator++()" << std::endl;
        return ++m_nData;
    }

    int operator++(int)
    {
        std::cout << "operator++(int)" << std::endl;
        int nData = m_nData;
        m_nData++;

        return nData;
    }

private:
    /* data */

    int m_nData = 0;
};

int main(int argc, const char *argv[])
{
    CMyData a(10);

    std::cout << ++a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    return 0;
}
