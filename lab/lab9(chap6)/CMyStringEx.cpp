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
