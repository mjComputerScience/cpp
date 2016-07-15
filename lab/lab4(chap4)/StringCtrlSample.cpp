#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
    std::cout << strParam << std::endl;
}

int main(int argc, const char *argv[])
{
    CMyString strData("Hello");

    ::TestFunc(strData);
    ::TestFunc(CMyString("World"));

    ::TestFunc("Hello, world!"); // explicit 때문에 변환 불가
    return 0;
}
