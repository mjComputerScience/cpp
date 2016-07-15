#include "MyString.h"

int main(int argc, const char *argv[])
{
    CMyString strLeft("Hello"), strRight("World"), strResult;

    strResult = strLeft + strRight;
    std::cout << strResult << std::endl;

    std::cout << strLeft << std::endl;
    strLeft += CMyString("world");
    std::cout << strLeft << std::endl;

    return 0;
}
