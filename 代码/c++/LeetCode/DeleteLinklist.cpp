#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteLNode(ListNode *head, int val)
{
    if (!head)
        return head;
    if (head->val == val)
        return head->next;
    ListNode *pre = head, *tmp = head;
    while (tmp->val != val)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    pre->next = tmp->next;
    return head;
};

int main()
{
    int s[100], n;
    cin >> n;

    ListNode head;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        head(s[i]);
    }
    return 0;
}