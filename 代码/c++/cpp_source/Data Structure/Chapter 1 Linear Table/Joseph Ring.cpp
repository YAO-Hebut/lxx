//经典约瑟夫环问题，用循环链表解决

#include <iostream>
using namespace std;
typedef struct CLinkList
{
    int data;
    struct CLinkList *next;
} node;
int main()
{
    //建立循环链表
    node *L, *r, *s;
    L = new node;
    r = L;
    int n, m, i;
    cin >> n;
    cin >> m;
    int k = m;
    for (i = 1; i <= n; i++) //尾插法建立链表
    {
        s = new node;
        s->data = i;
        r->next = s;
        r = s;
    }
    r->next = L->next; //让最后一个结点指向第一个有数据结点
    node *p;
    p = L->next;
    delete L; //删除第一个空的结点
              ///模拟解决约瑟夫问题
    while (p->next != p)
    {
        for (i = 1; i < k - 1; i++)
        {
            p = p->next;
        }
        cout << p->next->data << ' ';
        p->next = p->next->next; //将该节点从链表上删除。
        p = p->next;
    }
    cout << p->data << endl;
    return 0;
}
