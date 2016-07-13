#include <iostream>

void Swap (int &a, int &b);

void SwapC (int *a, int *b);

int main(int argc, const char *argv[])
{
    int aList[5] = {50, 40, 30, 20, 10};
    int i = 0, j = 0, idx = 0;

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if(aList[i] > aList[j])
                Swap(aList[i], aList[j]);
                // SwapC(&aList[i], &aList[j]);
        }
    } 

    std::cout << "aList[5] = { ";
    for (auto i : aList) {
        std::cout << i << ' ';
    }
    std::cout << '}' << std::endl;

    return 0;
}
void Swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SwapC (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
