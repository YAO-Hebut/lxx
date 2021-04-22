// 7-2 求集合交集 (20 分)
// 求整数集合A与整数集合B的交集。
// 输入格式:
// 输入有三行：
// 第一行是A和B的元素个数m和n（m,n <=100）；
// 第二行是集合A的m个元素；
// 第三行是集合A的n个元素。
// 输出格式:
// 输出交集的所有元素（按照在A集合出现的顺序输出，最后一个输出后面没有空格）。 若交集为空，输出“NULL”。
// 输入样例:
// 在这里给出一组输入。例如：
// 3 4
// 10 9 2
// 9 10 8 0
// 输出样例:
// 在这里给出相应的输出。例如：
// 10 9

#include <iostream>
using namespace std;
typedef struct LNode *List;
struct LNode
{
    int Data;
    struct LNode *Next;
};

List ReadList(int n);
List Intersection(List L1, List L2);
void PrintList(List L);

int main()
{
    List L1, L2, L;
    int e1, e2;
    scanf("%d%d", &e1, &e2);
    L1 = ReadList(e1);
    L2 = ReadList(e2);
    L = Intersection(L1, L2);
    PrintList(L);
    return 0;
}

List ReadList(int n)
{
    List L, head, s;
    L = (List)malloc(sizeof(struct LNode));
    head = L;
    for (int i = 1; i <= n; i++)
    {
        int e;
        scanf("%d", &e);
        s = (List)malloc(sizeof(struct LNode));
        s->Data = e;
        s->Next = NULL;
        L->Next = s;
        L = L->Next;
    }
    L = head->Next;
    free(head);
    return L;
}
List Intersection(List L1, List L2)
{
    List L, t1, t2, s, head;
    t1 = L1, t2 = L2;
    L = (List)malloc(sizeof(struct LNode)); //L还是用来把一个个S节点串起来的(先初始化空链表)
    L->Next = NULL;
    head = L;
    while (t1)
    {
        t2 = L2;
        while (t2)
        {
            if (t2->Data == t1->Data)
            {
                s = (List)malloc(sizeof(struct LNode));
                s->Data = t1->Data; //S当作一个个节点被L串起来
                s->Next = NULL;
                L->Next = s;
                L = L->Next;
                break;
            }
            t2 = t2->Next;
        }
        t1 = t1->Next;
    }
    L = head->Next; //回到头节点
    free(head);
    return L;
}
void PrintList(List L)
{
    if (L == NULL)
        printf("\n");
    else
    {
        printf("%d", L->Data);
        L = L->Next;
        while (L)
        {
            printf(" %d", L->Data);
            L = L->Next;
        }
    }
}