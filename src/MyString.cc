#include "MyString.h"

CMyString::CMyString()
    :m_nLength(0), m_pszData(nullptr)
{

}

CMyString::CMyString(const CMyString &rhs)
    :m_nLength(0), m_pszData(nullptr)
{
    this->SetString(rhs.m_pszData);
}

CMyString::CMyString(const char *pszParam)
    :m_nLength(0), m_pszData(nullptr)
{
    this->SetString(pszParam);
}

CMyString::CMyString(CMyString &&rhs)
    :m_nLength(0), m_pszData(nullptr)
{
    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    rhs.m_pszData = nullptr;
    m_nLength = 0;
}

CMyString & CMyString::operator=(const CMyString &rhs)
{
    if (this != &rhs) 
        SetString(rhs.m_pszData);

    return *this;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
    CMyString temp(*this);
    temp.Append(rhs.GetString());

    return temp;
}

CMyString &CMyString::operator+=(const CMyString &&rhs)
{
    Append(rhs.GetString());

    return *this;
}

int CMyString::operator==(const CMyString &rhs)
{
    if (m_pszData != nullptr && rhs.m_pszData != nullptr) 
    {
        if (strcmp(m_pszData, rhs.m_pszData) == 0) 
        {
            return 1;
        }
       
        return 0;
    }
}

int CMyString::operator!=(const CMyString &rhs)
{
    if(m_pszData!= nullptr && rhs.m_pszData != nullptr)
    {
        if (strcmp(m_pszData, rhs.m_pszData) == 0) 
        {
           return 0; 
        }

        return 1;
    }
}

CMyString operator+(const char *pszParam, const CMyString &strParam)
{
   CMyString strResult(pszParam);
   std::cout << strParam.m_pszData << std::endl;
   strResult.Append(strParam.m_pszData);

   return strResult;
}

char CMyString::operator[](int nIndex) const
{
   return m_pszData[nIndex]; 
}

char &CMyString::operator[](int nIndex)
{
   return m_pszData[nIndex];
}

CMyString::operator char *() const
{
    return m_pszData;
} 
CMyString::~CMyString()
{
    Release();
}

int CMyString::SetString(const char *pszParam)
{
    //check already has string
    Release();

    if(pszParam == nullptr)
        return 0;

    int nLength = strlen(pszParam);

    if(nLength == 0)
        return 0;

    m_pszData = new char[nLength + 1];

    strncpy(m_pszData, pszParam, sizeof(char) * (nLength + 1));
    m_nLength = nLength;

    m_nLength = OnSetString(m_pszData);
    return m_nLength;
}

int CMyString::OnSetString(char *pszData)
{
    return m_nLength; 
}

const char *CMyString::GetString() const
{
    return m_pszData;
}

int CMyString::GetLength() const
{
    return m_nLength;
}

int CMyString::Append(const char *pszParam)
{
    if (pszParam == nullptr) 
    {
        return 0;
    }

    int nLenParam = strlen(pszParam);

    if (nLenParam == 0) 
    {
        return 0;
    }

    if (m_pszData == nullptr) 
    {
        SetString(pszParam);

        return m_nLength;
    }

    int nLenCur = m_nLength;

    char *pszResult = new char[nLenCur + nLenParam + 1];
    strncpy(pszResult, m_pszData, sizeof(char) * (nLenCur + 1));
    strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * nLenParam);

    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

    return m_nLength;
}

void CMyString::Release()
{
    if(m_pszData != nullptr)
    {
        delete[] m_pszData;
        m_pszData = nullptr;
        m_nLength = 0;
    }
}
