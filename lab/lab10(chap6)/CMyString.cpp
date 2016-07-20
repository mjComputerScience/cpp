#include <iostream>
#include "CMyString.h"

CMyString::CMyString()
    : m_pszData(NULL)
    , m_nLength(0)
{
    
}

CMyString::CMyString(CMyString &&rhs)
    : CMyString()
{
    std::cout << "CMyString 이동 생성자 호출" << std::endl;
    //얕은 복사를 수행해도 상관없다. 어차피 원본이 곧 소멸되기 때문이다!
    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    //원본 임시 객체의 멤버들은 초기화한다. 두 포인터가 동시에 한 대상을 가리키는 일을 막기 위해서.
    //절대로 해제하면 안 된다.
    rhs.m_pszData = NULL;
    rhs.m_nLength = 0; 
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

int CMyString::GetLength() const
{
    return m_nLength;
}
int CMyString::Append(const char* pszParam)
{
    //매개변수 유효성 검사
    if(pszParam == NULL)
        return 0;

    int nLenParam = strlen(pszParam);

    if(nLenParam ==0)
        return 0;

    //세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리함
    if(m_pszData == NULL)
    {
        SetString(pszParam);

        return m_nLength;
    }

    //현재 문자열의 길이 백업
    int nLenCur = m_nLength;

    // 두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당함
    char *pszResult = new char[nLenCur + nLenParam + 1];

    // 문자열 조합
    strncpy(pszResult, m_pszData, sizeof(char) * (nLenCur + 1));
    strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * (nLenParam + 1));

    // 기존 문자열 삭제 및 멤버 정보 갱신
    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

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
    this->SetString(rhs.GetString());
    return *this;
}
CMyString CMyString::operator+(const CMyString &rhs)
{
    CMyString newStr(*this);
    newStr.Append(rhs);
    return std::move(newStr);
}
CMyString& CMyString::operator+=(const CMyString &rhs)
{
    Append(rhs);
    return *this;
}
char& CMyString::operator[](int nParam)
{
    if(nParam < 0 || nParam >= this->m_nLength) // NULL문자까지 출력을 허용하려면 >=가 아니라 >를 써준다.
    {
        std::cout << "ERROR: Out of index!!" << std::endl; // 인덱스를 잘못 입력하면 NULL문자 출력
        return this->m_pszData[m_nLength];
    }
    return this->m_pszData[nParam];
}
char CMyString::operator[](int nParam) const
{
    if(nParam < 0 || nParam >= this->m_nLength) // NULL문자까지 출력 허용하려면 >=가 아니라 >를 써준다.
    {
        std::cout << "ERROR: Out of index!!" << std::endl;
        return 0;
    }
    return this->m_pszData[nParam];
}
int CMyString::operator==(const CMyString& rhs) const
{
    if(m_pszData != NULL && rhs.m_pszData != NULL)
        return !strncmp(this->m_pszData, rhs.m_pszData, m_nLength > rhs.m_nLength ? m_nLength + 1 : rhs.m_nLength + 1);
    else if (m_pszData == NULL && rhs.m_pszData == NULL)
        return 1;
    else
        return 0;
}
int CMyString::operator!=(const CMyString& rhs) const
{
    if(m_pszData != NULL && rhs.m_pszData != NULL)
        return strncmp(this->m_pszData, rhs.m_pszData, m_nLength > rhs.m_nLength ? m_nLength + 1 : rhs.m_nLength + 1);
    else if (m_pszData == NULL && rhs.m_pszData == NULL)
        return 0;
    else
        return 1;
}
