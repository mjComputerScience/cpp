#include <iostream>
using namespace std;

class MyImage
{
public:
    MyImage(int nHeight, int nWidth) : m_nHeight(nHeight), m_nWidth(nWidth)
    {
        std::cout << "MyImage(int, int)" << std::endl;
    }

    int GetHeight() const
    {
        return m_nHeight;
    }

    int GetWidth() const
    {
        return m_nWidth;
    }

protected:
    int m_nHeight;
    int m_nWidth;
};

class MyShape
{
public:
    MyShape(int nType) : m_nType(nType)
    {
        std::cout << "MyShape(int)" << std::endl;
    }

    int GetType() const
    {
        return m_nType;
    }

protected:
    int m_nType;
};

class MyPicture : public MyImage, public MyShape
{
public:
    MyPicture() : MyImage(200, 120), MyShape(1)
    {
        std::cout << "MyPicture()" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    MyPicture a;

    std::cout << "Width: " << a.GetWidth() << std::endl;
    std::cout << "Height: " << a.GetHeight() << std::endl;
    std::cout << "Type: " << a.GetType() << std::endl;
    return 0;
}
