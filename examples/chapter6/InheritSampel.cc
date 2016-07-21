#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData(){std::cout << "CMyData()" << std::endl;}
    int GetData() { return m_nData; }
    void SetData(int nParam)
    {
        m_nData = nParam;
    }

protected:
    void PrintData()
    {
        std::cout << "CMyData::PrintData()" << std::endl;
    }

private:
    /* data */

    int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
    CMyDataEx() { std::cout << "CMyDataEx()" << std::endl; }
    void TestFunc()
    {
        PrintData();
        SetData(5);
        std::cout << CMyData::GetData() << std::endl;
    }

private:
    /* data */
};


int main(int argc, const char *argv[])
{
    CMyDataEx data;

    data.SetData(10);
    std::cout << data.GetData() << std::endl;

    data.TestFunc();
    
    return 0;
}
