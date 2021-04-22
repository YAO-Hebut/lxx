#include <stdio.h>
int main()
{
    int odd[1000] = {'\0'};  //奇数
    int even[1000] = {'\0'}; //偶数
    int N = 0, i = 0, j = 0;
    int count = 2;
    scanf("%d", &N); //输入人数
    int snap = -1;
    while (N--)
    { //入队
        scanf("%d", &snap);
        if (snap % 2)
            odd[i++] = snap;
        else
            even[j++] = snap;
    }
    i = j = 0;
    while (odd[i] != '\0' && even[j] != '\0')
    { //出队   按AAB的顺序
        while (count-- && odd[i])
        { //先输出A窗口处理完的两人
            printf("%d", odd[i++]);
            if (odd[i] != '\0' || even[j] != '\0') //当两窗口都还有人时输出" "
                printf(" ");
        };
        if (count == -1) //后输出B窗口处理完的一人
        {
            count = 2;
            printf("%d", even[j++]);
            if (even[j] != '\0' || odd[i] != '\0') //当两窗口都还有人时输出" "
                printf(" ");
        }
    };
    while (odd[i])
    { //若一个窗口输出完毕最后输出另一窗口剩下的人
        printf("%d", odd[i++]);
        if (odd[i] != '\0') //当还有人时输出" "没人时则不输出
            printf(" ");
    };
    while (even[j])
    { //若一个窗口输出完毕最后输出另一窗口剩下的人
        printf("%d", even[j++]);
        if (even[j] != '\0') //当还有人时输出" "没人时则不输出
            printf(" ");
    };
    return 0;
}