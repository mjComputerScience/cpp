#include "CMyString.h"
#include "CMyStringEx.h"

int main(int argc, const char *argv[])
{
    CMyStringEx strTest;

    // 문자열이 필터링되어 대체되는 경우
    strTest.SetString("멍멍이아들");
    std::cout << strTest << std::endl;


    strTest.SetString("Hello");
    std::cout << strTest << std::endl;

    return 0;
}
