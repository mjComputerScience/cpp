//
//  MyString.hpp
//  StringCtrlSample
//
//  Created by YooTae-Ook on 2016. 7. 29..
//  Copyright © 2016년 YooTae-Ook. All rights reserved.
//

#pragma once
#include <iostream>
//#include <string.h>
using namespace std;

class CMyString{
public:
    CMyString();
    
    explicit CMyString(const char *pszParam);
    
    CMyString(const CMyString &rhs); //복사생성자
    CMyString(CMyString &&rhs); //이동생성자
    ~CMyString();
    
private:
    char* m_pszData;
    
    int m_nLength;
    
public:
    int SetString(const char* pszParam);
    const char* GetString() const; //읽기만 수행하므로 상수화
    void Release();
    CMyString operator =(const CMyString &rhs); //
    operator char*() const{
        return m_pszData;
    }
    int GetLength() const;
    int Append(const char * pszParam);
    CMyString operator+(const CMyString &rhs);
    CMyString operator+=(const CMyString &rhs);
};