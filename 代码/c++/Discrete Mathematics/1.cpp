#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <cstdio>
using namespace std;

//合取
int hequ(int p, int q)
{
    int s;
    if (p > 0 && q > 0)
    {
        s = 1;
    }
    else
        s = 0;
    return s;
}

//吸取
int xiqu(int p, int q)
{
    int s;
    if (p == 0 && q == 0)
    {
        s = 0;
    }
    else if (p > 0 || q > 0)
    {
        s = 1;
    }
    return s;
}
//条件
int tiaojian(int p, int q)
{
    int s;
    if (p > 0 && q == 0)
    {
        s = 0;
    }
    else
        s = 1;
    return s;
}

//双条件
int shuangtiaojian(int p, int q)
{
    int s;
    if ((p > 0 && q > 0) || (p == 0 && q == 0))
    {
        s = 1;
    }
    else
        s = 0;
    return s;
}

//用二维数组为真值表赋值
int table2[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int table3[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
int table4[16][4] = {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}, {1, 1, 0, 1}, {1, 0, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
//*"合取",+"析取",!"非",>"条件",<"双条件"
int prior(char ch) //确定优先级
{
    switch (ch)
    {
    case '!':
        return 5;
    case '+':
        return 3;
    case '*':
        return 4;
    case '>':
        return 2;
    case '<':
        return 1;
    default:
        return 0;
    }
}
bool isOperator(char ch) //判断是否为运算操作符
{
    switch (ch)
    {
    case '!':
    case '+':
    case '*':
    case '>':
    case '<':
        return true;
    default:
        return false;
    }
}
stack<char> s1; //s1作为中缀表达式转后缀表达式的“中间过渡栈”
stack<int> s2;
string getPostfix(string &infix) //中缀表达式转后缀表达式
{
    string postfix;
    while (!s1.empty())
        s1.pop(); //先将s1清空
    int i, j, k;
    char tmp;
    for (i = 0; i < infix.size(); i++)
    {
        tmp = infix[i];      //tmp存储的是后缀表达式的各个值(包括变元和运算符以及括号)
        if (isOperator(tmp)) //当tmp为运算符时
        {
            while (!s1.empty() && isOperator(s1.top()) && prior(s1.top()) >= prior(tmp))
            {
                postfix.push_back(s1.top()); //当s1的栈顶为运算符且比新的tmp元素优先级高的话，就直接将新的低优先级运算符写入后缀表达式中
                s1.pop();
            }
            s1.push(tmp); //不满足上述条件则新的tmp元素入栈s1
        }
        else if (tmp == '(') //当元素为左括号"("时直接入栈写入后缀表达式中
        {
            s1.push(tmp);
        }
        else if (tmp == ')') //当元素为右括号")"时一直出栈，直到遇到左括号"("为止
        {
            while (s1.top() != '(')
            {
                postfix.push_back(s1.top());
                s1.pop();
            }
            s1.pop();
        }
        else if (tmp >= 'A' && tmp <= 'Z') //当元素为字母时直接出栈写入后缀表达式中
            postfix.push_back(tmp);
        else
        {
            printf("请输入合法的表达式\n");
            break;
        }
    }
    while (!s1.empty()) //最后遍历完整个表达式后依次将s1栈中元素出栈写入后缀表达式中
    {
        postfix.push_back(s1.top());
        s1.pop();
    }
    return postfix;
}
int Calculate(const string &postfix) //计算后缀表达式
{
    int left, right; //只需弹出左右两个值进行计算即可
    int flag;        //记录结果的真值
    while (!s2.empty())
        s2.pop(); //清空s2
    for (int i = 0; i < postfix.size(); ++i)
    {
        char c = postfix[i];
        switch (c)
        {
        case '+': //合取运算
            right = s2.top();
            s2.pop();
            left = s2.top();
            s2.pop();
            if (left == 0 && right == 0)
                flag = 0;
            else
                flag = 1;
            s2.push(flag); //得出结果后重新压入栈中
            break;
        case '*': //吸取运算
            right = s2.top();
            s2.pop();
            left = s2.top();
            s2.pop();
            if (left == 1 && right == 1)
                flag = 1;
            else
                flag = 0;
            s2.push(flag); //得出结果后重新压入栈中
            break;
        case '>': //条件运算
            right = s2.top();
            s2.pop();
            left = s2.top();
            s2.pop();
            if (left == 1 && right == 0)
                flag = 0;
            else
                flag = 1;
            s2.push(flag); //得出结果后重新压入栈中
            break;
        case '<': //非条件运算
            right = s2.top();
            s2.pop();
            left = s2.top();
            s2.pop();
            if (left == right)
                flag = 1;
            else
                flag = 0;
            s2.push(flag); //得出结果后重新压入栈中
            break;
        case '!': //非
            flag = s2.top();
            s2.pop();
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
            s2.push(flag); //得出结果后重新压入栈中
            break;
        default:
            s2.push(c - '0'); //不为运算符时直接将变元的真值存入栈s2
            break;
        }
    }
    int result = s2.top(); //最后栈s2中只剩下计算的后缀表达式的真值结果，返回即可
    s2.pop();              //清空栈s2
    return result;
}
int Print(string &tmp, char name[], int n) //真值表输出
{
    //tmp是中缀式，tmp2是后缀式，n是变量的个数
    string tmp2;
    tmp2 = getPostfix(tmp); //先将中缀式转换为后缀式
    int i, j, k, m;
    m = tmp2.size(); //m保存后缀式的长度
    if (n == 1)
    {
        printf("%5c", name[0]); //输出表头(变元名字)
        printf("    ");
        cout << tmp << endl; //输出中缀式(也是表头)
        for (j = 0; j < 2; j++)
        {
            string tmp1 = tmp2; //将后缀式赋给临时字符串，用于计算
            printf("%5d", j);
            i = 0;
            while (i < m)
            {
                if (tmp1[i] == name[0])
                    tmp1[i] = j + '0'; //相当于真值带入的过程
                i++;
            }
            printf("%5d\n", Calculate(tmp1));
        }
    }
    else if (n == 2)
    {
        for (i = 0; i < 2; i++)
            printf("%5c", name[i]);
        printf("    ");
        cout << tmp << endl; //输出中缀式
        for (j = 0; j < 4; j++)
        {
            string tmp1 = tmp2; //将后缀式赋给临时字符串，用于计算
            for (k = 0; k < 2; k++)
                printf("%5d", table2[j][k]);
            i = 0;
            while (i < m)
            {
                if (tmp1[i] == name[0]) //相当于真值带入的过程
                    tmp1[i] = table2[j][0] + '0';
                else if (tmp1[i] == name[1])
                    tmp1[i] = table2[j][1] + '0';
                i++;
            }
            printf("%5d\n", Calculate(tmp1));
        }
    }
    else if (n == 3)
    {
        for (i = 0; i < 3; i++)
            printf("%5c", name[i]);
        printf("    ");
        cout << tmp << endl; //输出中缀式
        for (j = 0; j < 8; j++)
        {
            string tmp1 = tmp2; //将后缀式赋给临时字符串，用于计算
            for (k = 0; k < 3; k++)
                printf("%5d", table3[j][k]);
            i = 0;
            while (i < m)
            {
                if (tmp1[i] == name[0]) //相当于真值带入的过程
                    tmp1[i] = table3[j][0] + '0';
                else if (tmp1[i] == name[1])
                    tmp1[i] = table3[j][1] + '0';
                else if (tmp1[i] == name[2])
                    tmp1[i] = table3[j][2] + '0';
                i++;
            }
            printf("%5d\n", Calculate(tmp1));
        }
    }
    else if (n == 4)
    {
        for (i = 0; i < 4; i++)
            printf("%5c", name[i]);
        printf("    ");
        cout << tmp << endl; //输出中缀式
        for (j = 0; j < 16; j++)
        {
            string tmp1 = tmp2; //将后缀式赋给临时字符串，用于计算
            for (k = 0; k < 4; k++)
                printf("%5d", table4[j][k]);
            i = 0;
            while (i < m) //相当于真值带入的过程
            {
                if (tmp1[i] == name[0])
                    tmp1[i] = table4[j][0] + '0';
                else if (tmp1[i] == name[1])
                    tmp1[i] = table4[j][1] + '0';
                else if (tmp1[i] == name[2])
                    tmp1[i] = table4[j][2] + '0';
                else if (tmp1[i] == name[3])
                    tmp1[i] = table4[j][3] + '0';
                i++;
            }
            printf("%5d\n", Calculate(tmp1));
        }
    }
}
bool judge(char name[]) //判断变量名是否合法
{
    int i, n = strlen(name);
    if (n >= 5)
        return false;
    for (i = 0; i < n; i++)
        if (name[i] < 'A' || name[i] > 'Z')
            return false;
    return true;
}

int main()
{
    int i, n, y;
    char variablename[10];
    printf("------------------------------------------------\n");
    printf("         欢迎使用真值计算程序！！！\n");
    printf("------------------------------------------------\n");
    printf("计算两个命题的四则运算请输入1，计算命题公式的真值表请输入2\n");
    cin >> y;
    if (y == 1)
    {
        int p, q;
        cout << "请输入P,Q的真值" << endl;
        cin >> p >> q;
        cout << "P ∧ Q=" << hequ(p, q) << "    "
             << "P ∨ Q=" << xiqu(p, q) << "    "
             << "P → Q=" << tiaojian(p, q) << "    "
             << "P ↔ Q=" << shuangtiaojian(p, q) << endl;
    }
    else if (y == 2)
    {
        while (1)
        {
            printf("请您输入变量名(温馨提示:变量名均为大写字母,变量名之间不能有空格,可输入Esc退出本程序)\n");
            scanf("%s", variablename); //输入变量名
            if (strcmp(variablename, "Esc") == 0)
                break;
            n = strlen(variablename);
            if (!judge(variablename)) //判断变量名输入是否合法
            {
                printf("表达式不合法或者变元超过四个,请重新输入\n");
                continue;
            }
            string postfixtmp;
            printf("请您输入合法表达式(*表示合取,+表示析取，!表示非，>表示条件,<表示双条件)\n");
            cin >> postfixtmp;
            Print(postfixtmp, variablename, n); //输出真值表
        }
    }
    else
        cout << "输入错误，程序退出" << endl;
    return 0;
}