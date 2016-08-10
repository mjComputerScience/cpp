#include "UserData.h"
#include <iostream>

CUserData::CUserData(void)
{
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    nUserDataCounter++;
}
CUserData::CUserData(const char* pszName, const char* pszPhone)
    : CUserData() // call non-argument constructor
{
    strncpy(szName, pszName, sizeof(szName));
    strncpy(szPhone, pszPhone, sizeof(szPhone));
}
CUserData::~CUserData(void)
{
    nUserDataCounter--;
}

int CUserData::nUserDataCounter = 0;

const char* CUserData::GetKey(void)
{
    return GetName();
}
void CUserData::PrintNode(void)
{
    printf("[%p] %s\t%s [%p]\n",
            this,
            szName, szPhone,
            GetNext());
}
