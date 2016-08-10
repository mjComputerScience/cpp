#include "USerData.h"

CUserData::CUserData(void)
    :pNext(nullptr)
{
    nUserDataCounter++;
}

CUserData::~CUserData(void)
{
    
}

int CUserData::nUserDataCounter = 0;
