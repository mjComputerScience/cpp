//
//  MyStringEx.cpp
//  StringCtrlSample
//
//  Created by YooTae-Ook on 2016. 8. 9..
//  Copyright © 2016년 YooTae-Ook. All rights reserved.
//

#include "MyStringEx.hpp"

CMyStringEx::CMyStringEx(){
    
}
CMyStringEx::CMyStringEx(const char* pszParam):CMyString(pszParam){
    
}
CMyStringEx::~CMyStringEx(){
    
}

int CMyStringEx::Find(const char * pszParam){
    if(pszParam == NULL || GetString() == NULL)
        return -1;
    
    const char *pszResult = strstr(GetString(), pszParam);
    
    if(pszResult != NULL)
        return pszResult - GetString();
    
    return -1;
}

int CMyStringEx::SetString(const char* pszParam){
    int nResult;
    if(strcmp(pszParam, "멍멍이 아들")==0)
        nResult = CMyString::SetString("착한사람");
    else
        nResult = CMyString::SetString(pszParam);
    
    return nResult;
}