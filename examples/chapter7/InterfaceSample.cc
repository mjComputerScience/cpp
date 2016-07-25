#include <iostream>
using namespace std;


class MyObject
{
public:
    MyObject()
    {
        std::cout << "MyObject()" << std::endl;
    }
    virtual ~MyObject(){}

    virtual int GetDeviceID() const = 0;

protected:
    int deviceID;
};

class MyTV : public MyObject
{
public:
    MyTV(int ID)
    {
        deviceID = ID;
    }
    virtual ~MyTV(){}

    virtual int GetDeviceID() const
    {
        std::cout << "MyTV::GetDeviceID()" << std::endl;
        return deviceID;
    }
};

class MyPhone : public MyObject
{
public:
    MyPhone(int ID)
    {
        deviceID = ID;
    }
    virtual ~MyPhone(){}

    virtual int GetDeviceID() const
    {
        std::cout << "MyPhone::GetDeviceID()" << std::endl;
        return deviceID;
    }
};

void PrintID(MyObject *Obj)
{
    std::cout << "Device ID: " << Obj->GetDeviceID() << std::endl;
}


int main(int argc, const char *argv[])
{
    MyTV a(5);
    MyPhone b(5);

    PrintID(&a);
    PrintID(&b);

    return 0;
}
