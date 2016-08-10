#include "MyIterator.h"
#include "MyNode.h"

CMyIterator::CMyIterator(CMyNode *pHead)
    : m_pHead(nullptr), m_pCurrent(nullptr)
{
    m_pHead = pHead;
    m_pCurrent = pHead->pNext;
}

CMyIterator::~CMyIterator()
{
    m_pCurrent = nullptr;
    m_pHead = nullptr;
}
