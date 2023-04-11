/*
 * @file    :example_2.2.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-07
 * @brief   :50个学生，求分数在80分以上的学生的学号和成绩。
 *          :
 *          :
 */

#include <stdio.h>

int main()
{
    int n[50+10], g[50+10];
    for(int i = 1; i<=50; i++){
        scanf("%d\t%d", n+i, g+i);
    } 
    for(int i = 1; i<=50; i++){
        if(g[i] >= 80)
            printf("%d\t%d\n", n[i], g[i]);
    }
    return 0;
}
