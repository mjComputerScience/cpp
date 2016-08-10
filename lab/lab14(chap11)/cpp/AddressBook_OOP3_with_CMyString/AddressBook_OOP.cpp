#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int main(int argc, const char *argv[])
{
    CUserData* header = new CUserData();

    CMyList DB(header);
    CUserInterface UI(DB);
    UI.Run();

    delete header;

    return 0;
}
