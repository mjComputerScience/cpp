#include <iostream>

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
    CMyString &operator = (const CMyString &rhs);

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
    void Release();

};
