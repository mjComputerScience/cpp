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
    std::cout << "Call CMyString constructor" << std::endl;

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

CMyString operator+(const CMyString &rhs)
{
    Append(rhs.GetString());
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
    Release()

    for (int i = 0; i < pszParam[i] != '\0'; i++) 
    {
        m_nLength++;
    }

    if (m_nLength > 0) 
    {
        m_pszData = new char[m_nLength + 1];

        for (int i = 0; i <= m_nLength; i++) {
            m_pszData[i] = pszParam[i];
        }

        m_pszData[m_nLength] = '\0';
    }

    return 0;
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

    strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
    strcpy_s(pszResult + (sizeof(char) * nLenCur),
            sizeof(char) * (nLenParam + 1), pszParam);

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
