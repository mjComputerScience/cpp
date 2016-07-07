#include "MyString.h"

int main(int argc, const char *argv[])
{
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    //copy generate
    CMyString strNewData(strData);
    std::cout << strNewData.GetString() << std::endl;
    
    // operator=
    strNewData = strTest;
    std::cout << strNewData.GetString() << std::endl;

    return 0;
}
