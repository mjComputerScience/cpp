#include <iostream>

using namespace std;


class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual void Draw()
    {
        std::cout << "Shape::Draw()" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    virtual void Draw()
    {
        std::cout << "Rectangle::Draw()" << std::endl;
    }
};

class Circle : public Shape
{
public:
    virtual void Draw()
    {
        std::cout << "Circle::Draw()" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    int input = 0;
    std::cout << "Choose number of shape [1: Rectangle, 2: Circle]" << std::endl;
    std::cin >> input;

    Shape *shape = nullptr;
    
    if (input == 1)
    {
        shape = new Rectangle; 
    }

    else if(input == 2)
    {
        shape = new Circle;
    }

    else
    {
        shape = new Shape;
    }

    shape->Draw();

    Rectangle *pRect = dynamic_cast<Rectangle *>(shape);

    if(pRect != nullptr)
    {
        std::cout << "Rectangle::Draw()" << std::endl;
    }

    else
    {
        Circle *pCircle = dynamic_cast<Circle *>(shape);

        if(pCircle != nullptr)
        {
            std::cout << "Circle::Draw()" << std::endl;
        }

        else
            std::cout << "Shape::Draw()" << std::endl;
    }

    return 0;
}
