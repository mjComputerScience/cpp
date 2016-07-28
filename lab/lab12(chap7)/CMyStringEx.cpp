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
void CMyStringEx::OnSetString(char *pszData, int nLength)
{
    int mongmongSize = strlen("멍멍이아들");
    if(strncmp(pszData, "멍멍이아들", nLength + 1 > mongmongSize ? nLength + 1 : mongmongSize ) == 0)
    {
        strncpy(pszData, "*착한아들*", sizeof(char) * (nLength + 1));
    }
}
