#include <iostream>
#include <string.h>

using namespace std;

class CIntArray
{
public:
    CIntArray(int nSize)
    {
        //memory allocate
        m_pnData = new int[nSize];
        //memory initialize
        memset(m_pnData, 0, sizeof(int) * nSize);
    }

    ~CIntArray(){ delete m_pnData; }

    int operator[](int nIndex) const
    {
        std::cout << "operator[] const" << std::endl;
        return m_pnData[nIndex];
    }

    int &operator[](int nIndex)
    {
        std::cout << "operator[]" << std::endl;
        return m_pnData[nIndex];
    }

private:
    /* data */
    int *m_pnData;
    int m_nSize;
};

void TestFunc(const CIntArray &arParam)
{
    std::cout << "TestFunc()" << std::endl;

    std::cout << arParam[3] << std::endl;
}

int main(int argc, const char *argv[])
{
    CIntArray arr(5);

    for (int i = 0; i < 5; i++) 
    {
        arr[i] = i * 10;
    }

    TestFunc(arr);

    return 0;
}
