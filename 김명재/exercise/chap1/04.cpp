/* Int에 대한 참조 형식을 매개변수로 받고 두 변수의 값을 교환하는 함수를 작성하세요. 함수 원형은 void Swap(int &a ,int &b) 입니다. */

#include <iostream>

void Swap (int &a, int &b);

int main(int argc, const char *argv[])
{
    int a = 10, b = 20;

    std::cout << "a: "<<a<<", b: "<<b << std::endl;
    Swap(a, b);
    std::cout << "a: "<<a<<", b: "<<b << std::endl;
    
    return 0;
}

void Swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
