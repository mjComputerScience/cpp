#include <stdio.h>
/** #include <conio.h> */
/** conio.h는 윈도우 전용 헤더다. */
#include <stdlib.h>
#include <string.h>

// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "Address.dat"

void ReleaseList();

/////////////////////////////////
typedef struct _USERDATA
{
    char szName[32];    // name
    char szPhone[32];   // phone number

    struct _USERDATA *pNext;
} USERDATA;

// dummy head nome
USERDATA g_Head = {0};


/////////////////////////////////
// searching function
USERDATA *FindNode(char *pszName)
{
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL)
    {
        if(strcmp(pTmp->szName, pszName) == 0)
            return pTmp;

        pTmp = pTmp -> pNext;
    }

    // 일치하는 데이터를 찾지 못한 경우
    return NULL;
}

//////////////////////////////////
int AddNewNode(char* pszName, char* pszPhone)
{
    USERDATA *pNewUser = NULL;

    //같은 이름이 이미 존재하는지 확인한다.
    if(FindNode(pszName) != NULL)
        return 0;

    // 메모리를 확보한다.
    pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
    memset(pNewUser, 0, sizeof(USERDATA));

    // 메모리 값을 저장한다.
    /** sprintf_s 대신 snprintf */
    snprintf(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
    snprintf(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
    pNewUser->pNext = NULL;

    //더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에
    //추가한 데이터가 가장 앞쪽에 온다.
    pNewUser->pNext = g_Head.pNext;
    g_Head.pNext = pNewUser;

    return 1;
}

//////////////////////////////////////
// 이름을 입력받아 리스트에 추가하는 함수
void Add()
{
    char szName[32] = {0};
    char szPhone[32] = {0};
    char* tempStr = NULL;

    printf("Input name : ");
    /** fflush대신 rewind */
    rewind(stdin);

    fgets(szName, sizeof(szName), stdin);
    /** fgets는 \n까지 받으므로 \n을 NULL문자로 바꿔주어야 한다.
     * 지정한 크기를 넘도록 스트링을 받으면 \n를 받지 않는다. **/
    if( (tempStr=strchr(szName, '\n')) != NULL)
        *tempStr = '\0';


    tempStr = NULL;
    printf("Input phone number : ");
    /** fflush대신 rewind */
    rewind(stdin);

    fgets(szPhone, sizeof(szPhone), stdin);
    /** fgets는 \n까지 받으므로 \n을 NULL문자로 바꿔주어야 한다.
     * 지정한 크기를 넘도록 스트링을 받으면 \n를 받지 않는다. **/
    if( (tempStr=strchr(szPhone, '\n')) != NULL)
        *tempStr = '\0';

    AddNewNode(szName, szPhone);
}

///////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
    char szName[32] = {0};
    USERDATA *pNode = NULL;
    char* tempStr;

    printf("Input name : ");
    rewind(stdin);
    fgets(szName, sizeof(szName), stdin);
    if( (tempStr = strchr(szName, '\n')) != NULL)
        *tempStr = '\0';

    pNode = FindNode(szName);
    if(pNode != NULL)
    {
        printf("[%p] %s\t%s [%p]\n",
                pNode,
                pNode->szName, pNode->szPhone,
                pNode->pNext);
    }

    else
    {
        puts("ERROR: 데이터를 찾을 수 없습니다.");
    }

    /** _getch(); */
    getchar();
}

///////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력하는 함수

void PrintAll()
{
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL)
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

///////////////////////////////////////
// 특정 노드를 검색하고 삭제하는 함수
int RemoveNode(char* pszName)
{
    USERDATA* pPrevNode = &g_Head;
    USERDATA* pDelete = NULL;

    while(pPrevNode->pNext != NULL)
    {
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->szName, pszName) == 0)
        {
            pPrevNode->pNext = pDelete->pNext;
            free(pDelete);

            return 1;
        }

        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

///////////////////////////////////////////
// 이름을 받아 자료를 검색하고 삭제하는 함수
void Remove()
{
    char szName[32] = {0};
    char* tempStr;

    printf("Input name : ");
    rewind(stdin);
    fgets(szName, sizeof(szName), stdin);
    if( (tempStr = strchr(szName, '\n')) != NULL)
        *tempStr = '\0';

    RemoveNode(szName);
}

//////////////////////////////////////////////
// 메뉴를 출력하는 UI함수

int PrintUI()
{
    int nInput = 0;

    /** System("cls"); */
    printf("\033c");

    printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

    // 사용자가 선택한 메뉴의 값을 반환한다.
    scanf("%3d", &nInput);
    rewind(stdin);

    return nInput;
}

////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 리스트를 완성하는 함수
int LoadList(char *pszFileName)
{
    FILE *fp = NULL;
    USERDATA user = {0};

    fp = fopen(pszFileName, "rb");
    if(fp == NULL)
        return 0;

    ReleaseList();

    while(fread(&user, sizeof(USERDATA), 1, fp))
        AddNewNode(user.szName, user.szPhone);

    fclose(fp);
    return 0;
}

//////////////////////////////////////////
// 리스트 형태로 존재하는 정보를 파일에 저장하는 함수

int SaveList(char *pszFileName)
{
    FILE *fp = NULL;
    USERDATA *pTmp = g_Head.pNext;

    fp = fopen(pszFileName, "wb");

    if(fp == NULL)
    {
        puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
        /** _getch(); */
        getchar();

        return 0;
    }

    while(pTmp != NULL)
    {
        if(fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
            printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp ->szName);

        pTmp = pTmp->pNext;
    }
    fclose(fp);

    return 1;
}

///////////////////////////////////////////////
// 리스트의 모든 데이터를 삭제하는 함수

void ReleaseList()
{
    USERDATA *pTmp = g_Head.pNext;
    USERDATA *pDelete = NULL;

    while(pTmp != NULL)
    {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        free(pDelete);
    }

    memset(&g_Head, 0, sizeof(USERDATA));
}

int main(int argc, const char *argv[])
{
    int nMenu = 0;
    LoadList(DATA_FILE_NAME);

    // 메인 이벤트 반복문
    while((nMenu = PrintUI()) != 0)
    {
        switch(nMenu)
        {
        case 1: // Add
            Add();
            break;

        case 2: // Search
            Search();
            break;
        
        case 3: // Print all
            PrintAll();
            break;

        case 4: // Remove
            Remove();
            break;
        }
    }

    // 종료 전에 파일로 저장하고 메모리를 해제한다.
    SaveList(DATA_FILE_NAME);
    ReleaseList();
    return 0;
}
