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

private:
    Node headNode;
};

int main(int argc, const char *argv[])
{
    MyList list;

    list.AddNewNode("KI");
    list.AddNewNode("MJ");
    list.AddNewNode("IZ");

    return 0;
}
