/*
 * @file    :example_1.3.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-06
 * @brief   :两个整数中较大数
 *          :
 *          :
 */

#include <stdio.h>
int main()
{
    int max(int x, int y);
    int a, b, c;
    scanf("%d,%d", &a, &b);//注意输入格式 eg: 5,6 而不是5 6
    c = max(a, b);
    printf("max = %d\n", c);
    return 0;
}

int max(int x, int y)
{
    int z;
    if (x > y)
        z = x;
    else
        z = y;
    return z;
}