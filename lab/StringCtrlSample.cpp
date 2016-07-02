#include "MyString.h"

int main(int argc, const char *argv[])
{
    CMyString strData;
    strData.SetString("Hello1");
    std::cout << strData.GetString() << std::endl;
    std::cout << strData.GetLength() << std::endl;
    strData.SetString("Hello234");
    std::cout << strData.GetString() << std::endl;
    std::cout << strData.GetLength() << std::endl;
    strData.SetString("");
    std::cout << strData.GetString() << std::endl;
    std::cout << strData.GetLength() << std::endl;
    strData.SetString(NULL);
    std::cout << strData.GetString() << std::endl;
    std::cout << strData.GetLength() << std::endl;

    return 0;
}
