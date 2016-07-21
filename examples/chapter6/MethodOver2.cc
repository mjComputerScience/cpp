#include <iostream>

using namespace std;

class CMyData
{
public:
    int GetData() { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    /* data */
    int m_nData = 0;
};


class CMyDataEx : public CMyData
{
public:

    void SetData(int nParam)
    {
        if (nParam < 0) 
        {
            CMyData::SetData(0);
        }

        if (nParam > 10) 
        {
            CMyData::SetData(10);
        }
    }

};

int main(int argc, const char *argv[])
{
    CMyDataEx a;
    CMyData &rData = a;
    rData.SetData(15);

    std::cout << rData.GetData() << std::endl;

    CMyData *pData = new CMyDataEx;
    pData->SetData(5);
    std::cout << pData->GetData() << std::endl;
    delete pData; 

    return 0;
}
