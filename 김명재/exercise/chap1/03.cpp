/* char[12] 배열 메모리를 new 연산자로 동적 할당하고 해제하는 코드 예를 작성하세요. */

#include <iostream>

int main(int argc, const char *argv[])
{
    char *pChar = new char[12];

    delete[] pChar;

    return 0;
}
