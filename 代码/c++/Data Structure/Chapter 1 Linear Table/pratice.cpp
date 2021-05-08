#include <iostream>
using namespace std;

typedef struct LNode *List;
struct LNode
{
    int Data;
    struct LNode *Next; //链表的尾指针指向下一节点，若无下一节点则指向NULL(所有尾指针都初始化为NULL)
};

List InitList(int n)
{
    List L, head, S;
    L = (List)malloc(sizeof(struct LNode)); //动态分配存储空间
    head = L;
    for (int i = 1; i <= n; i++)
    {
        int e;
        scanf("%d", &e);
        S = (List)malloc(sizeof(struct LNode)); //S是用来构造一个个节点的
        S->Data = e;
        S->Next = NULL; //尾指针初始化为NULL
        L->Next = S;    //L用来把一个个S节点串起来形成链表
        L = L->Next;    //指针后移
    }
    L = head->Next; //回到头节点
    free(head);     //释放head节点(head就是用来让L链表构造完成后回到头节点的)
    return L;
}