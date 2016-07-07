#include <iostream>

using namespace std;

int nData = 200;

namespace TEST
{
    int nData = 100;
    void TestFunc(void)
    {
        std::cout << nData << std::endl;
    }
}

int main(int argc, const char *argv[])
{
    TEST::TestFunc();
    return 0;
}


