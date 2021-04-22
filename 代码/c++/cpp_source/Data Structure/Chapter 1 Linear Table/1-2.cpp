#include <stdio.h>

#include <stdlib.h>

#define ERROR 0

#define OK 1

typedef int ElemType;

typedef struct LNode
{

    ElemType Data;

    struct LNode *Next;

} LNode, *List;

List Create_L();

List CombineToL(List L1, List L2);

int main()
{

    List L, L1, L2;

    int m, n, i;

    L1 = Create_L();

    L2 = Create_L();

    L = CombineToL(L1, L2);

    if (!L)

        printf("NULL"); //链表为空时

    else
    {

        while (L->Next)
        {

            printf("%d ", L->Data);
            L = L->Next;
        }
        printf("%d", L->Data);
    }
    return 0;
}

List Create_L()
{

    List head, L, pro;

    int n;

    L = (List)malloc(sizeof(LNode));

    head = L;

    scanf("%d", &n);

    if (n == -1)
    {

        L = NULL;

        return L;
    }

    while (1)
    {

        if (n == -1)
        { //序列结束符号

            pro->Next = NULL; //序列尾指向NULL

            free(L); //释放多余节点

            return head;
        }

        L->Data = n;

        L->Next = (List)malloc(sizeof(LNode));

        pro = L;

        L = L->Next;

        scanf("%d", &n);
    }
}

List CombineToL(List L1, List L2)
{

    List L, head;

    L = (List)malloc(sizeof(LNode)); //建立一个空节点，起到头结点的作用，便于后续拼接

    head = L;

    while (L1 && L2)
    {

        if (L1->Data <= L2->Data)
        {

            L->Next = L1;

            L = L->Next;

            L1 = L1->Next;
        }

        else
        {
            L->Next = L2;
            L = L->Next;
            L2 = L2->Next;
        }
    }

    if (L1)
    { //L2进行到空或者L2初始为空

        L->Next = L1;

        L = head;

        head = head->Next;

        free(L);

        return head;
    }

    else if (L2)
    { //L1进行到空或者L1初始为空

        L->Next = L2;

        L = head;

        head = head->Next;

        free(L);

        return head;
    }

    else //两者初始皆为空

        return NULL;
}