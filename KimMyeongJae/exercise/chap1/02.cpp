/* C++11에서 auto 예약어는 어떤 의미인지 쓰고 코드로 예를 보이세요 */

#include <iostream>

int main(int argc, const char *argv[])
{
    // auto 예약어는 초깃값에 따라 자동으로 변수 타입을 정해준다.
    int a = 10;
    auto b(a);

    b = 20;

    std::cout << "a: "<<a<<", b: "<<b << std::endl;
    return 0;
}
