#pragma once

#include "MyNode.h"
#include "MyIterator.h"

#define MAX_STR_SIZE 32

// 노드 클래스에 대한 알림 선언
class CMyNode;

class CMyList
{
public:
    CMyList(CMyNode *pHead);
    ~CMyList(void);

protected:
    void ReleaseList(void);
    CMyNode *m_pHead;

public:
    CMyNode* FindNode(const char* pszKey);
    int AddNewNode(CMyNode *pNewNode);
    //
    // UI 코드. 설계상 바람직하지 않다.
    // void PrintAll(void);
    int RemoveNode(const char* pszKey);

    static char* DATA_FILE_NAME;
    int LoadList(char *pszFileName);
    int SaveList(char *pszFileName);

    // 열거자를 생성한다.
    CMyIterator MakeIterator(void);

    // 데이터가 추가될 때마다 호출되는 가상함수
    virtual int OnAddNewNode(CMyNode* pNewNode);

    /** strncmp를 쉽게 사용하기 위해 MJstrcmp를 만듦 **/
    int MJstrcmp(const char* str1, const char* str2);
};
