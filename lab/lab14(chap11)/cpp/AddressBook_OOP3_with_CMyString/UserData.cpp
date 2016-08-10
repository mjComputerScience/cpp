#include "UserData.h"
#include <iostream>

CUserData::CUserData(void)
{
    nUserDataCounter++;
}
CUserData::CUserData(const char* pstrName, const char* pstrPhone)
    : CUserData() // call non-argument constructor
{
    strncpy(strName, pstrName, sizeof(strName));
    strncpy(strPhone, pstrPhone, sizeof(strPhone));
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
