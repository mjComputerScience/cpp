#include <iostream>
using namespace std;


class MyData
{
public:
    MyData(int param) : data(param) {}

    int GetData() const
    {
        return data;
    }

    void SetData(int param)
    {
        data = param;
    }

   friend void PrintData(const MyData &);

private:
    int data;
};

void PrintData(const MyData &rData)
{
    std::cout << "PrintData(): " << rData.data << std::endl;
}

int main(int argc, const char *argv[])
{
    MyData a(6);
    PrintData(a);

    return 0;
}
