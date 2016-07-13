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
CMyString::CMyString(const CMyString &rhs)
    :CMyString()
{
/*     this->m_nLength = rhs.m_nLength;
 *
 *     this->Release();
 *     this->m_pszData = new char[this->m_nLength + 1];
 * 
 *     strcpy(this->m_pszData, rhs.m_pszData);
 *     위에 코드.. 그냥 SetString()이랑 같은건데... */
    this->SetString(rhs.GetString());
}

CMyString::CMyString(const char* str)
    :CMyString()
{
    this->SetString(str);
}
CMyString::operator char*(void) const
{
    return const_cast<char*>(this->GetString());
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
CMyString& CMyString::operator=(const CMyString &rhs)
{
/*     this->m_nLength = rhs.m_nLength;
 * 
 *     this->Release();
 *     this->m_pszData = new char[this->m_nLength + 1];
 * 
 *     strcpy(this->m_pszData, rhs.m_pszData);
 *     위에 코드... 역시나 SetString이랑 같은건데..  */

    if(this != &rhs) // 자기 자신이면 그냥 리턴해준다. 답지 참고했음.
        this->SetString(rhs.GetString());
    return *this;
}
