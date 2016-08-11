#include "MyList.h"
#include "UserData.h"
#include <iostream>

char* CMyList::DATA_FILE_NAME = new char[32];

CMyList::CMyList(CMyNode *pHead)
{
    m_pHead = pHead;
    
    char datName[32] = "Address.dat";
    strncpy(DATA_FILE_NAME, datName, sizeof(datName));
    LoadList(DATA_FILE_NAME);
}

CMyList::~CMyList()
{
    SaveList(DATA_FILE_NAME);
    ReleaseList();
    delete[] DATA_FILE_NAME;
}

int CMyList::LoadList(char *pszFileName)
{
    FILE *fp = nullptr;
    CUserData* user = nullptr;

    fp = fopen(pszFileName, "rb");
    if(fp == nullptr)
        return 0;

    ReleaseList();

    while(fread((user = new CUserData()), sizeof(CUserData), 1, fp))
        AddNewNode(user);

    fclose(fp);
    return 1;
}

int CMyList::SaveList(char *pszFileName)
{
    FILE *fp = NULL;
    CMyNode *pTmp = m_pHead->pNext;

    fp = fopen(pszFileName, "wb");

    if(fp == nullptr)
    {
        puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
        /** _getch(); */
        getchar();
        rewind(stdin);

        return 0;
    }

    while(pTmp != nullptr)
    {
        if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
            printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp ->GetKey());

        pTmp = pTmp->pNext;
    }
    fclose(fp);
    return 1;
}

int CMyList::AddNewNode(CMyNode *pNewNode)
{
    if(FindNode(pNewNode->GetKey()) != nullptr)
    {
        /** 겹치는 key가 있을 때 에러메세지 추가 **/
        printf("ERROR: 이미 %s을/를 가진 인스턴스가 존재합니다.", pNewNode->GetKey());
        getchar();
        rewind(stdin);
        delete pNewNode;
        return 0;
    }

    // 미래를 위해 추가해놓는 OnAddNewNode
    if(OnAddNewNode(pNewNode))
    {
        pNewNode->pNext = m_pHead->pNext;
        m_pHead->pNext = pNewNode;

        return 1;
    }

    return -1;
}

CMyNode* CMyList::FindNode(const char* pszName)
{
    CMyNode *pTmp = m_pHead->pNext;
    while(pTmp != nullptr)
    {
        if(MJstrcmp(pTmp->GetKey(), pszName) == 0)
            return pTmp;

        pTmp = pTmp -> pNext;
    }

    // 일치하는 데이터를 찾지 못한 경우
    return nullptr;
}

int CMyList::RemoveNode(const char* pszName)
{
    CMyNode* pPrevNode = m_pHead;
    CMyNode* pDelete = nullptr;

    while(pPrevNode->pNext != nullptr)
    {
        pDelete = pPrevNode->pNext;

        if(MJstrcmp(pDelete->GetKey(), pszName) == 0)
        {
            pPrevNode->pNext = pDelete->pNext;
            delete pDelete;

            return 1;
        }

        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

void CMyList::ReleaseList(void)
{
    CMyNode *pTmp = m_pHead->pNext;
    CMyNode *pDelete = nullptr;

    while(pTmp != nullptr)
    {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }
}

CMyIterator CMyList::MakeIterator()
{
    CMyIterator it(m_pHead);
    return it;
}

int CMyList::OnAddNewNode(CMyNode *pNewNode)
{
    return 1;
}

int CMyList::MJstrcmp(const char* str1, const char* str2)
{
    int str1Size = strnlen(str1, MAX_STR_SIZE);
    int str2Size = strnlen(str2, MAX_STR_SIZE);

    return strncmp(str1, str2, str1Size > str2Size ? str1Size : str2Size);
}
