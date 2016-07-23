#include "MyStringEx.h" 

int main(int argc, const char *argv[])
{
    CMyStringEx strLeft("Hello"), strRight("It's me");
    std::cout << strLeft + strRight << std::endl;

    return 0;
}
