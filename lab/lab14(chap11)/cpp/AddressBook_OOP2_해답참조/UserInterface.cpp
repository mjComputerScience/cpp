#include "UserInterface.h"
#include "UserData.h"
#include <iostream>

CUserInterface::CUserInterface(CMyList &rList)
    : m_List(rList)
{
    
}

CUserInterface::~CUserInterface()
{
    
}

void CUserInterface::Add(void)
{
    char szName[32] = {0};
    char szPhone[32] = {0};
    char *tempStr = nullptr;

    printf("Input name : ");
    /** fflush대신 rewind */
    rewind(stdin);

    fgets(szName, sizeof(szName), stdin);
    /** fgets는 \n까지 받으므로 \n을 NULL문자로 바꿔주어야 한다.
     * 지정한 크기를 넘도록 스트링을 받으면 \n를 받지 않는다. **/
    if( (tempStr=strchr(szName, '\n')) != nullptr)
        *tempStr = '\0';


    tempStr = nullptr;
    printf("Input phone number : ");
    /** fflush대신 rewind */
    rewind(stdin);

    fgets(szPhone, sizeof(szPhone), stdin);
    /** fgets는 \n까지 받으므로 \n을 NULL문자로 바꿔주어야 한다.
     * 지정한 크기를 넘도록 스트링을 받으면 \n를 받지 않는다. **/
    if( (tempStr=strchr(szPhone, '\n')) != nullptr)
        *tempStr = '\0';


    m_List.AddNewNode(new CUserData(szName, szPhone));
}

void CUserInterface::Search(void)
{
    char szName[32] = {0};
    CMyNode *pNode = nullptr;
    char* tempStr = nullptr;

    printf("Input name : ");
    rewind(stdin);
    fgets(szName, sizeof(szName), stdin);
    if( (tempStr = strchr(szName, '\n')) != nullptr)
        *tempStr = '\0';

    pNode = m_List.FindNode(szName);
    if(pNode != nullptr)
    {
        pNode->PrintNode();
    }

    else
    {
        puts("ERROR: 데이터를 찾을 수 없습니다.");
    }

    /** _getch(); */
    getchar();
}

void CUserInterface::Remove(void)
{
    char szName[32] = {0};
    char* tempStr = nullptr;

    printf("Input name : ");
    rewind(stdin);
    fgets(szName, sizeof(szName), stdin);
    if( (tempStr = strchr(szName, '\n')) != nullptr)
        *tempStr = '\0';

    m_List.RemoveNode(szName);
}

int CUserInterface::PrintUI(void)
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

int CUserInterface::Run(void)
{
    int nMenu = 0;

    //메인 이벤트 반복문
    while((nMenu = PrintUI()) != 0)
    {
        switch(nMenu)
        {
            case 1: //Add
                Add();
                break;
            case 2: //Search
                Search();
                break;
            case 3: //Print all
                /** 여기 PrintAll()이 아니라 m_List.PrintAll() 아닌가? **/
                m_List.PrintAll();
                break;
            case 4: //Remove
                Remove();
                break;
        }
    }

    return nMenu;
}
