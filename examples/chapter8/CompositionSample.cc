#include <iostream>
#include <string.h>
using namespace std;


class Node
{
    friend class MyList;
        
public:
    explicit Node(const char *param_name)
    {
        strncpy(name, param_name, sizeof(name));
    }

private:
    char name[32];
    Node *next = nullptr;
};

class MyList
{
public:
    MyList() : headNode("Dummy head") {}
    ~MyList()
    {
        Node *pNode = headNode.next;
        Node *pDelete = nullptr;

        while (pNode) 
        {
            pDelete = pNode;
            pNode = pNode->next;

            std::cout << pDelete->name << std::endl;
            delete pDelete;
        }

        headNode.next = nullptr;
    }

    void AddNewNode(const char *param_name)
    {
        Node *pNode = new Node(param_name);

        pNode->next = headNode.next;
        headNode.next = pNode;
    }

    void Print()
    {
        Node *pNode = headNode.next;

        while (pNode) 
        {
            std::cout << pNode->name << std::endl;
            pNode = pNode->next;
        }
    }

private:
    Node headNode;
};

class MyUI
{
public:
    
    int PrintMenu()
    {
        // system("clear");
        std::cout << "[1]Add\n" << "[2]Print\n" << "[3]Exit\n" << std::endl;
        cout.flush();

        int menuSelector = 0;
        std::cin >> menuSelector;

        return menuSelector;
    }

    void Run()
    {
        char name[32];
        int menuSelector = 0;

        while ((menuSelector = PrintMenu()) > 0) 
        {
           switch (menuSelector) 
           {
               case 1:
                   std::cout << "Name : ";
                   cout.flush();
                   std::cin >> name;
                   myList.AddNewNode(name);

                   break;

               case 2:
                   myList.Print();

                   break;

               default:
                   break;
           }
        }
    }

private:
    MyList myList;
};

int main(int argc, const char *argv[])
{
    MyUI ui;
    ui.Run();

    return 0;
}
