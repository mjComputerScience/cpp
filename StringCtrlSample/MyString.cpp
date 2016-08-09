//
//  MyString.cpp
//  StringCtrlSample
//
//  Created by YooTae-Ook on 2016. 7. 29..
//  Copyright © 2016년 YooTae-Ook. All rights reserved.
//

#include "MyString.hpp"
#include <string.h>

CMyString::CMyString():m_pszData(nullptr), m_nLength(0){
    
}
//변환생성자
CMyString::CMyString(const char *pszParam):m_pszData(nullptr), m_nLength(0){
    SetString(pszParam);
}

//복사생성자
CMyString::CMyString(const CMyString &rhs):m_pszData(nullptr), m_nLength(0){
    this->SetString(rhs.GetString());
}
//이동생성자
CMyString::CMyString(CMyString &&rhs):m_pszData(nullptr), m_nLength(0){
    cout<<"CMyString 이동 생성자 호출"<<endl;
    
    //얕은 복사를 해도 상관없다. 어차피 원본이 곧 소멸하기 때문이다.
    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;
    
    //원본 임시객체의 멤버들은 다 초기화된다. 절대로 해제하면 안됨.
    rhs.m_pszData = rhs.m_pszData;
    rhs.m_nLength = 0;
}

CMyString::~CMyString(){
    Release();
}

int CMyString::SetString(const char* pszParam){
    Release(); //재호출을 고려하여, 앞에 선언한다.
    
    if(pszParam == nullptr) //만약 문자열이 입력 안 되었다면.
        return 0;
    
    int nLength = (int)strlen(pszParam); //문자열의 길이를 구한다.(long으로 나오므로 int로 cast한다.)
    
    if(nLength == 0) //문자열의 길이가 0 일경우.
        return 0;
    
    m_pszData = new char[nLength + 1]; //'\0'을 포함하는 길이로 배열을 동적할당한다.
    
    strcpy(m_pszData, pszParam); //pszParam으로 받은 문자열을 m_pszData에 복사한다.
    m_nLength = nLength; //문자열의 길이를 설정한다.
    
    return nLength;
}

const char* CMyString::GetString() const{
    return m_pszData;
}

void CMyString::Release(){
    if(m_pszData != nullptr)
        delete [] m_pszData; //m_pszData가 가리키는 값을 NULL(0)로 만든다. 가리키던 주소는 유지한다.
    
    m_pszData = nullptr; //가리키던 주소 자체를 nullptr(0x)으로 만든다.
    m_nLength = 0; //이전의 문자열의 길이를 초기화한다.
}

CMyString CMyString::operator=(const CMyString &rhs){
    
    if(this != &rhs)
        this->SetString(rhs.GetString());
    
    return *this;
}

int CMyString::GetLength() const{
    return m_nLength;
}

int CMyString::Append(const char* pszParam){
    if(pszParam == NULL) // 매개변수 유효성 검사
        return 0;
    
    int nLenParam = (int)strlen(pszParam);
    
    if(nLenParam == 0)
        return 0;
    
    if(m_pszData == NULL){
        SetString(pszParam);
        
        return m_nLength;
    }
    
    int nLenCur = m_nLength;
    
    char* pszResult = new char[nLenCur + nLenParam + 1];
    
    strncpy(pszResult, m_pszData, sizeof(char) * (nLenCur + 1));
    strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * nLenParam);
    
    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;
    
    return m_nLength;
}

CMyString CMyString::operator+(const CMyString &rhs){
    CMyString strResult(m_pszData);
    strResult.Append(rhs.GetString());
    return strResult;
}

CMyString CMyString::operator+=(const CMyString &rhs){
    Append(rhs.GetString());
    
    return *this;
}


