#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
    std::cout << strParam[0] << std::endl;
    std::cout << strParam[strParam.GetLength() - 1] << std::endl;
}

int main(int argc, const char *argv[])
{
    CMyString strParam("HelloWorld");
    std::cout << strParam << std::endl;
    TestFunc(strParam);
    return 0;
}
