#include "MyString.h"

CMyString TestFunc()
{
    CMyString strTest("TestFunc() return");
     std::cout << strTest << std::endl;

     return strTest;
}

int main(int argc, const char *argv[])
{
    TestFunc();

    return 0;
}
