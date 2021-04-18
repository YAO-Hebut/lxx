#include <stdio.h>
#include <string.h>

const int TRUE = 1;
const int FALSE = 0;
const int STR_MAX_SIZE = 100;
typedef int status;
typedef char ElemType;
typedef struct Stack
{
    int stack_size;
    ElemType *bottom;
    ElemType *top;
};

status IsPlalindrome(char *s);

int main()
{
    char str_input[STR_MAX_SIZE];
    printf("请输入待检测的字符串");
    gets_s(str_input);
    if (IsPlalindrome)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

status IsPlalindrome(char *s)
{
    int len;
    char *p;
    Stack stack;
    len = strlen(s) / 2; //栈的长度为1/2 字符串s的长度
    p = s;

    stack.bottom = new char[len];
    stack.stack_size = len;
    stack.top = stack.bottom; //初始化栈

    for (int i = 0; i < stack.stack_size; i++)
    {
        *(stack.top) = *p;
        stack.top++;
        p++;
    } //前半部分入栈

    if (stack.stack_size % 2 == 1) //当字符串为奇数个时，最中间的字符无需比较，直接跳过
    {
        p++;
    }

    while (stack.top != stack.bottom)
    {
        if (*(stack.top - 1) != *p)
        {
            delete[] stack.bottom; //stack.bottom是new出来的，所以必须delete掉
            return FALSE;
        }
        else
        {
            stack.top--;
            p++;
        }
    }
    if (stack.top == stack.bottom)
    {
        delete[] stack.bottom; //stack.bottom是new出来的，所以必须delete掉
        return TRUE;
    }
}