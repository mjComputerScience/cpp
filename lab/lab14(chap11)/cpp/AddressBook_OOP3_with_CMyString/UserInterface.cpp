#include "UserInterface.h"
#include "UserData.h"
#include "MyList.h" // MAX_STR_SIZE 쓰기 위해 추가
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
    if( (tempStr=static_cast<char*>(memchr(szName, '\n', MAX_STR_SIZE))) != nullptr) /** strchr() 대신 memchr()을 쓰자 **/
        *tempStr = '\0';


    tempStr = nullptr;
    printf("Input phone number : ");
    /** fflush대신 rewind */
    rewind(stdin);

    fgets(szPhone, sizeof(szPhone), stdin);
    /** fgets는 \n까지 받으므로 \n을 NULL문자로 바꿔주어야 한다.
     * 지정한 크기를 넘도록 스트링을 받으면 \n를 받지 않는다. **/
    if( (tempStr=static_cast<char*>(memchr(szPhone, '\n', MAX_STR_SIZE))) != nullptr) /** strchr() 대신 memchr()을 쓰자 **/
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
    rewind(stdin);
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
    /** scanf 형식지정자에 제한을 걸어서 buffer overflow 방지 **/
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
                this->PrintAll();
                break;
            case 4: //Remove
                Remove();
                break;
        }
    }

    return nMenu;
}

void CUserInterface::PrintAll(void)
{
    // 리스트에 대한 열거자를 생성한다.
    CMyIterator it = m_List.MakeIterator();
    CUserData *pNode = nullptr;

    //열거자를 이용해 리스트 전체에 접근한다.
    while((pNode = static_cast<CUserData*> (it.GetCurrent())) != nullptr)
    {
        pNode->PrintNode();
        it.MoveNext();
    }

    printf("CUserData Counter : %d\n", CUserData::GetUserDataCounter() - 1);

    getchar();
    rewind(stdin);
}
