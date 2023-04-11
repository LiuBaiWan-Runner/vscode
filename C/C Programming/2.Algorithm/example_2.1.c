/*
 * @file    :example_2.1.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-07
 * @brief   :计算1*2*3*4*5, 即5！
 *          :计算1*3*5*7*9*11
 *          :
 */

#include <stdio.h>

int factorial(int num)
{
    int ans = 1;
    for (int i = 2; i <= num; i++)
    {
        ans *= i;
    }
    return ans;
}

int multiplication(int num)
{
    int ans = 1;
    for (int i = 3; i <= num; i += 2)
        ans *= i;
    return ans;
}

int main()
{
    printf("ans1 = %d\n", factorial(5));
    printf("ans2 = %d\n", multiplication(11));
    return 0;
}