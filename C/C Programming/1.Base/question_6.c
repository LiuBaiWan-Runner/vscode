/*
 * @file    :question_6.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-06
 * @brief   :三个数中最大值
 *          :
 *          :
 */

#include <stdio.h>

// int max(int x, int y, int z)
// {
//     // 这个方法使用条件（三目）运算符（ ？ ： ）求三个数的最大值
//     // 这里由于条件运算符的从右至左的结合性，省略两个括号
//     // 原为 x > y ? ( x > z ? x : z ) : ( y > z ? y : z)
//     int max_num = x > y ? x > z ? x : z : y > z ? y : z;
//     return max_num;
// }

// int max(int x, int y, int z)
// {
//     // if else 分支方法，思路同上，通过这个方法更容易理解上边条件运算符
//     int max_num;
//     if(x > y)
//     {
//         if(x > z)
//             max_num = x;
//         else
//             max_num = z;
//     }
//     else{
//         if(y > z)
//             max_num = y;
//         else
//             max_num = z;
//     }
//     return max_num;
// }

int max(int x, int y, int z)
{
    // if else 分支方法，更改，直接返回函数值
    if(x > y)
    {
        if(x > z)
            return x;
        else
            return z;
    }
    else{
        if(y > z)
            return y;
        else
            return z;
    }
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("max = %d", max(a, b, c));
    return 0;
}
