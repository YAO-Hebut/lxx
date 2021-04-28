#include <stdio.h>
#include <string.h>

const int TRUE = 1;
const int FALSE = 0;
const int STR_MAX_SIZE = 100;
typedef int STATUS;
typedef char ElementType;
typedef struct
{
    int stack_size;
    ElementType *top;
    ElementType *base;
} STACK;

STATUS IsPlalindrome(char *s);
int main()
{
    //	char *str_input;  //之前这么定义的，导致程序在gets(str_input)处出错，后改成下一句
    char str_input[STR_MAX_SIZE];
    printf("\n请输入待检测的字符串：");
    gets_s(str_input);

    if (IsPlalindrome(str_input))
    {
        printf("\n是回文字符串！");
    }
    else
    {
        printf("\n不是回文字符串！");
    }
    return 0;
}

STATUS IsPlalindrome(char *s)
{
    int len;
    char *p;
    STACK stack;

    len = strlen(s) / 2;
    p = s;

    stack.base = new char[len];
    stack.top = stack.base;
    stack.stack_size = len;

    for (int i = 0; i < stack.stack_size; i++)
    {
        *(stack.top) = *p;
        stack.top++;
        p++;
    }

    if (stack.stack_size % 2 == 1) //当字符串为奇数个时，最中间的字符无需比较，直接跳过
    {
        p++;
    }
    while (stack.top != stack.base)
    {
        if (*(stack.top - 1) != *p)
        {
            delete[] stack.base;
            return FALSE;
        }
        else
        {
            stack.top--;
            p++;
        }
    }
    if (stack.top == stack.base)
    {
        delete[] stack.base;
        return TRUE;
    }
}