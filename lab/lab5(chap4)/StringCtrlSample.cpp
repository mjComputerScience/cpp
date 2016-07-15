#include "MyString.h"

CMyString TestFunc(void)
{
    CMyString strTest("TestFunc() return");
    std::cout << strTest << std::endl;

    return std::move(strTest);
}

int main(int argc, const char *argv[])
{
    CMyString a(TestFunc());

    return 0;
}
