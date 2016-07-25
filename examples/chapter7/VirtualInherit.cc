#include <iostream>

using namespace std;

class MyObject
{
public:
    MyObject()
    {
        std::cout << "MyObject()" << std::endl;
    }
    
    virtual ~MyObject() {  }
};

class MyImage : virtual public MyObject
{
public:
    MyImage()
    {
        std::cout << "MyImage(int, int)" << std::endl;
    }
};

class MyShape : virtual public MyObject
{
public:
    MyShape()
    {
        std::cout << "MyShape(int)" << std::endl;
    }
};

class MyPicture : public MyImage, public MyShape
{
public:
    MyPicture()
    {
        std::cout << "MyPicture()" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    MyPicture a;
    return 0;
}
