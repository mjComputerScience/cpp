#include "MyStringEx.h" 

int CMyStringEx::Find(const char *pszParam)
{
    //do if and only if there exist comparing and compared data both
    if(GetString() && pszParam)
    {
        const char *string_found = strstr(GetString(), pszParam);

        if (string_found) 
        {
            return string_found - GetString(); 
        }
    }

    return -1;
}

int CMyStringEx::SetString(const char *pszParam)
{
    if(strncmp(pszParam, "fuck", 4) == 0)
    {
        return CMyString::SetString("It's bad word boy");
    }

    else
        return CMyString::SetString(pszParam);
}
