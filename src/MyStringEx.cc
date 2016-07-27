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

int CMyStringEx::OnSetString(char *pszData)
{
    if(strncmp(pszData, "fuck", 4) == 0)
    {
        delete pszData;
        pszData = new char[9];
        strncpy(pszData, "bad word", 8);
        pszData[9] = '\0';
    }

    return strlen(pszData);
}
