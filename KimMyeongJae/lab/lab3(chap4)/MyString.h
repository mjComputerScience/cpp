#pragma once
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString();
    ~CMyString();
    CMyString(const CMyString &rhs);

private:
    char* m_pszData;
    int m_nLength;

public:
    int SetString(const char *pszParam);
    const char* GetString() const;
    void Release();
    int GetLength() const;

    CMyString& operator=(const CMyString &rhs);
};
