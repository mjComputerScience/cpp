#include "MyString.h"

int main(int argc, const char *argv[])
{
    CMyString strLeft("Test"), strRight("String");

    if (strLeft == strRight) 
    {
        std::cout << "same string" << std::endl;
    }

    else 
    {
        std::cout << "different string" << std::endl;
    }

    strLeft = CMyString("String");

    if (strLeft == strRight)
    {
        std::cout << "same" << std::endl;
    }

    else 
    {
        std::cout << "different" << std::endl;
    }

    return 0;
}
