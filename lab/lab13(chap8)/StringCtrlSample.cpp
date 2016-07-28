#include "CMyString.h"
#include "CMyStringEx.h"

int main(int argc, const char *argv[])
{
    CMyString b("World"), c;

    c = "Hello" + b;
    std::cout << c << std::endl;
    return 0;
}
