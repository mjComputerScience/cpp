#include <iostream>

using namespace std;

class MyData
{
public:
    MyData();
    virtual ~MyData(){}

    void SetData(int param)
    {
        data = param;
    }

    int GetData() const
    {
        return data;
    }

private:
    /* data */

    int data = 0;
};

class MyDataEx : public MyData
{
public:
    void SetData(int param)
    {
        if (param > 10) 
        {
            param = 10;
        }

        MyData::SetData(param);
    }

    void PrintData()
    {
        std::cout << "PrintData():" << GetData() << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    MyData *pData = new MyDataEx;
    MyData *NewData = nullptr;

    pData->SetData(15);

    //downcasting
    NewData = static_cast<MyDataEx>(pData);
    NewData->PrintData();
    delete pData;

    return 0;
}
