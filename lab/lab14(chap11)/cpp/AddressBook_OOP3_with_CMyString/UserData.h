#pragma once
#include "MyNode.h"
#include "CMyString.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode
{
public:
    CUserData(void);
    CUserData(const char* pszName, const char* pszPhone);
    ~CUserData(void);

    const char* GetName(void) const {return strName;}
    const char* GetPhone(void) const {return strPhone;}
    static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
    CMyString strName;    // 이름
    CMyString strPhone;   // 전화번호

    // pNext 멤버가 사라졌다!
    static int nUserDataCounter;

public:
    // 순수 가상 함수들 정의
    virtual const char* GetKey(void);
    virtual void PrintNode(void);
};
