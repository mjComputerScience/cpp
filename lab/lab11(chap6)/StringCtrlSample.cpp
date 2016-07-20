#include "CMyString.h"
#include "CMyStringEx.h"

int main(int argc, const char *argv[])
{
    CMyStringEx strLeft("Hello"), strRight("World");
    std::cout << strLeft + strRight << std::endl;

    return 0;
}
