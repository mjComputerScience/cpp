#include <iostream>

class MyUSB
{
public:
    virtual int GetUsbVersion() const = 0;
    virtual int GetTransferRate() const = 0;
};

class MySerial
{
public:
    virtual int GetSignal() const = 0;
    virtual int GetRate() const = 0;
};

class MyDevice : public MyUSB, public MySerial
{
public:
    //USB interface
    virtual int GetUsbVersion() const
    {
        return 0;
    }

    virtual int GetTransferRate() const
    {
        return 0;
    }

    //Serial interface
    virtual int GetSignal() const
    {
        return 0;
    }

    virtual int GetRate() const
    {
        return 0;
    }
};

int main(int argc, const char *argv[])
{
    MyDevice dev;
    return 0;
}
