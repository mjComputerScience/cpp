#include "MyList.h"
#include <iostream>

char* CMyList::DATA_FILE_NAME = new char[32];

CMyList::CMyList()
{
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
    FILE *fp = NULL;
    CUserData user;

    fp = fopen(pszFileName, "rb");
    if(fp == nullptr)
        return 0;

    ReleaseList();

    while(fread(&user, sizeof(CUserData), 1, fp))
        AddNewNode(user.szName, user.szPhone);

    fclose(fp);
    return 1;
}

int CMyList::SaveList(char *pszFileName)
{
    FILE *fp = NULL;
    CUserData *pTmp = m_Head.pNext;

    fp = fopen(pszFileName, "wb");

    if(fp == nullptr)
    {
        puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
        /** _getch(); */
        getchar();

        return 0;
    }

    while(pTmp != nullptr)
    {
        if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
            printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp ->szName);

        pTmp = pTmp->pNext;
    }
    fclose(fp);
    return 1;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
    CUserData* pNewUser = nullptr;

    //같은 이름이 이미 존재하는지 확인한다.
    if(FindNode(pszName) != nullptr)
        return 0;

    // 메모리를 확보한다.
    pNewUser = new CUserData();

    // 메모리 값을 저장한다.
    /** sprint_S 대신 snprintf */
    snprintf(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
    snprintf(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
    pNewUser->pNext = NULL;

    // 더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에
    // 추가한 데이터가 가장 앞쪽에 온다.
    pNewUser->pNext = m_Head.pNext;
    m_Head.pNext = pNewUser;

    return 1;
}

void CMyList::PrintAll(void)
{
    CUserData* pTmp = m_Head.pNext;
    while(pTmp != nullptr)
    {
        printf("[%p] %s\t%s [%p]\n",
                pTmp,
                pTmp->szName, pTmp->szPhone,
                pTmp->pNext);

        pTmp = pTmp->pNext;
    }
    
    /** _getch(); */
    getchar();
}

CUserData* CMyList::FindNode(const char* pszName)
{
    CUserData *pTmp = m_Head.pNext;
    while(pTmp != nullptr)
    {
        if(strcmp(pTmp->szName, pszName) == 0)
            return pTmp;

        pTmp = pTmp -> pNext;
    }

    // 일치하는 데이터를 찾지 못한 경우
    return nullptr;
}

int CMyList::RemoveNode(const char* pszName)
{
    CUserData* pPrevNode = &m_Head;
    CUserData* pDelete = nullptr;

    while(pPrevNode->pNext != nullptr)
    {
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->szName, pszName) == 0)
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
    CUserData *pTmp = m_Head.pNext;
    CUserData *pDelete = nullptr;

    while(pTmp != nullptr)
    {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }

    memset(&m_Head, 0, sizeof(CUserData));
}
