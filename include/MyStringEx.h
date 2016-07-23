#pragma once
#include "MyString.h"

using namespace std;

class CMyStringEx : public CMyString
{
public:
    using CMyString::CMyString;

    int Find(const char *pszParam);
    int SetString(const char *pszParam);

private:
    /* data */
};
