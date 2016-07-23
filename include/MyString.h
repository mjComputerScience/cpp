#pragma once
#include <iostream>
#include <string.h>

class CMyString
{
public:

    //default constructor
    CMyString();

    //copy constructor
    CMyString(const CMyString &rhs);

    //conversion constructor
    CMyString(const char *pszParam);

    //move semantic
    CMyString(CMyString &&rhs);

    //operator overloading
    CMyString &operator=(const CMyString &rhs);
    CMyString operator+(const CMyString &rhs);
    CMyString &operator+=(const CMyString &&rhs);
    int operator==(const CMyString &rhs);
    int operator!=(const CMyString &rhs);

    char operator[](int nIndex) const;
    char &operator[](int nIndex);
    
    //conversion operator
    operator char *() const;

    //default destructor
    ~CMyString();

private:
        
    char *m_pszData;
    int m_nLength;

public:

    int SetString(const char *pszParam);
    const char *GetString() const;
    int GetLength() const;
    int Append(const char *pszParam);
    void Release();

};
