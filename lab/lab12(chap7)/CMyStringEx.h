#include <iostream>
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
    using CMyString::CMyString;
    int Find(const char *pszParam);
    void OnSetString(char *pszData, int nLength);

private:
    /* data */
};
