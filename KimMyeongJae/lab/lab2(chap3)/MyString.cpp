#include <iostream>
#include "MyString.h"

CMyString::CMyString()
    : m_pszData(NULL)
    , m_nLength(0)
{
    
}
CMyString::~CMyString()
{
    Release();
}

int CMyString::SetString(const char *pszParam)
{
    Release();
    if(pszParam == NULL)
        return 0;

    int i = 0;

    for (i = 0; pszParam[i] != 0 ; i++);
    this->m_nLength = i;

    if(m_nLength == 0)
        return 0;

    this->m_pszData = new char[this->m_nLength + 1];

    for (i = 0; i <= this->m_nLength; i++) {
        m_pszData[i] = pszParam[i];
    }

    return 0;
}

const char* CMyString::GetString() const
{
    if(m_pszData == NULL)
        return "ERROR: String doesn't exists!";
    else
        return m_pszData;
}

int CMyString:: GetLength() const
{
    return m_nLength;
}

void CMyString::Release()
{
    if(m_pszData)
    {
        delete[] m_pszData;
    }
    m_pszData = NULL;
    m_nLength = 0;
}
