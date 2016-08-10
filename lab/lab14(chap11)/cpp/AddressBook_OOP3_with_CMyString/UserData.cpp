#include "UserData.h"
#include <iostream>

CUserData::CUserData(void)
{
    nUserDataCounter++;
}
CUserData::CUserData(const char* pszName, const char* pszPhone)
    : CUserData() // call non-argument constructor
{
    strName.SetString(pszName);
    strPhone.SetString(pszPhone);
}
CUserData::~CUserData(void)
{
    nUserDataCounter--;
}

int CUserData::nUserDataCounter = 0;

const char* CUserData::GetKey(void)
{
    return strName;
}
void CUserData::PrintNode(void)
{
    printf("[%p] %s\t%s [%p]\n",
            this,
            static_cast<char*>(strName), static_cast<char*>(strPhone),
            GetNext());
}
