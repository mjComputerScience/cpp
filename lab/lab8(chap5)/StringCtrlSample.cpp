#include "MyString.h"

int main(int argc, const char *argv[])
{
    CMyString strLeft("Test"), strRight("String");

    if(strLeft == strRight)
        std::cout << "Same" << std::endl;
    else    
        std::cout << "Different" << std::endl;

    strLeft = CMyString("String");

    if(strLeft != strRight)
        std::cout << "Different" << std::endl;
    else
        std::cout << "Same" << std::endl;

    return 0;
}
