#include "CMyString.h"
#include "CMyStringEx.h"

int main(int argc, const char *argv[])
{
    /* CMyStringEx strTest;
     * strTest.SetString("멍멍이아들");
     * std::cout << strTest << std::endl; */

    CMyString *strTest = new CMyStringEx();

    strTest->SetString("멍멍이아들");
    std::cout << *strTest << std::endl;

    delete strTest;
    return 0;
}
