#include <iostream>

int main(int argc, const char *argv[])
{
    char name[20] = {0};
    int age = 0;

    std::cout << "이름을 입력하세요:";
    std::cin >> name;
    std::cout << "나이를 입력하세요:";
    std::cin >> age;

    std::cout << "나의 이름은 " << name << "이고, "<< age<<"살입니다." << std::endl;
    return 0;
}
