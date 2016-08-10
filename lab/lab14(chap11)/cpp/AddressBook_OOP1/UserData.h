#pragma once

class CUserData
{
    friend class CMyList;

public:
    CUserData(void);
    ~CUserData(void);

    const char* GetName(void) const {return szName;}
    const char* GetPhone(void) const {return szPhone;}
    const CUserData* GetNext(void) const {return pNext;}

    static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
    char szName[32] = {0};    // 이름
    char szPhone[32] = {0};   // 전화번호

    CUserData *pNext;

    static int nUserDataCounter;
};
