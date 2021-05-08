#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    LNode *p = L;
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        p->next = new LNode;
        p = p->next;
        p->data = m;
        p->next = NULL;
    }
}

void InsertList(LinkList &L, int n, int x)
{
    LNode *p = L;
    if (p->next == NULL) //这种情况下是为空链表直接插入节点的
    {
        LNode *q = new LNode;
        q->data = x;
        q->next = NULL;
        p->next = q;
        p = q;
        return; //相当于插入算法结束，直接推出此算法(其他return也同理)
    }
    while (p->next != NULL)
    {
        LNode *temp = p;
        p = p->next;
        if (p->data == x)
            return;      //线性表中有与输入的值相等的情况
        if (p->data > x) //插入线性表之中的情况
        {
            LNode *q = new LNode;
            q->data = x;
            q->next = p;
            temp->next = q;
            return;
        }
    }

    LNode *q = new LNode;
    q->data = x;
    q->next = NULL;
    p->next = q;
    p = q; //插入表尾(表中无比它大的值时)的情况
    return;
}

void OutputList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL)
            cout << " ";
        p = p->next;
    }
}

int main()
{
    int n, x;
    cin >> n;
    LinkList L;
    CreateList(L, n);

    cin >> x;
    InsertList(L, n, x);
    OutputList(L);
    return 0;
}