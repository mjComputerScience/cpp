#include <iostream>

using namespace std;

class MyData
{
public:
    MyData(int param) : data(param)
    {

    }

    MyData operator+(const MyData &rhs)
    {
        return MyData(data + rhs.data);
    }

    MyData &operator=(const MyData &rhs)
    {
        data = rhs.data;

        return *this;
    }

    operator int()
    {
        return data;
    }


protected:
    int data = 0;
};

class MyDataEx : public MyData
{
public:
    MyDataEx(int param) : MyData(param)
    {
        
    }

    using MyData::operator+;
    using MyData::operator=;
};

int main(int argc, const char *argv[])
{
    MyData a(3), b(4);

    std::cout << a + b << std::endl;

    MyDataEx c(3), d(4), e(0);

    e = c + d;
    std::cout << e << std::endl;
    
    return 0;
}
