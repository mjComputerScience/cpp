#include <iostream>
#include "CMyStringEx.h"

int CMyStringEx::Find(const char *pszParam)
{
    const char* originStr = GetString();
    const char* tmpStr = strstr(originStr, pszParam);

    if(tmpStr != nullptr)
        return static_cast<int>( tmpStr - originStr );
    else
        return -1;
}

int CMyStringEx::SetString(const char *pszParam)
{
    CMyString::SetString(pszParam);

    if(Find("멍멍이아들") != -1)
        CMyString::SetString("착한 사람");

    return 0;
}
