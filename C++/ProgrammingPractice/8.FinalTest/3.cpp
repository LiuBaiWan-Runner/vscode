/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :
 *          :
 *          :
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, i, k, j, s[100000] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &j);
        s[j] = 1;
    }
    for (j = 1; j <= n; j++)
    {
        if (s[j] == 1)
        {
            printf("%d ", j);
        }
    }
    return 0;
}