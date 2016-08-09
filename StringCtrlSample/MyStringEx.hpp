//
//  MyStringEx.hpp
//  StringCtrlSample
//
//  Created by YooTae-Ook on 2016. 8. 9..
//  Copyright © 2016년 YooTae-Ook. All rights reserved.
//

#pragma once
#include "MyString.hpp"

class CMyStringEx :public CMyString{
public:
    CMyStringEx();
    CMyStringEx(const char* pszParam);
    ~CMyStringEx();
    int Find(const char * pszParam);
    int SetString(const char* pszParam);
};
