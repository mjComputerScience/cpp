#pragma once
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString();
    ~CMyString();

    // 이동 생성자
    CMyString(CMyString &&rhs);
    // 복사 생성자
    CMyString(const CMyString &rhs);
    // 변환 생성자
    CMyString(const char* str);

private:
    char* m_pszData;
    int m_nLength;

public:
    operator char*(void) const;
    int SetString(const char *pszParam);
    const char* GetString() const;
    void Release();
    int GetLength() const;

    CMyString& operator=(const CMyString &rhs);
};
