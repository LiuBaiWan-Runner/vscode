/*
 * @file    :example_2.3.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-07
 * @brief   :判断闰年
 *          :闰年(leap year)：能被4整除但是不能被100整除，或者能被400整除
 *          :
 */

#include <stdio.h>

int main()
{
    // // 单独的if条件判断
    // int year;
    // scanf("%d", &year);
    // if(year % 4 == 0 && year % 100 != 0){
    //     printf("%d是闰年\n", year);
    //     return 0;
    // }
    // if(year % 400 == 0){
    //     printf("%d是闰年\n", year);
    //     return 0;
    // }
    // printf("%d不是闰年\n", year);
    // return 0;

    // if...else...条件分支
    // int year;
    // scanf("%d", &year);
    // if(year % 4 == 0 && year % 100 != 0){
    //     printf("%d是闰年\n", year);
    //     return 0;
    // }
    // else if(year % 400 == 0){
    //     printf("%d是闰年\n", year);
    //     return 0;
    // }
    // else
    //     printf("%d不是闰年\n", year);
    // return 0;

    // for(int year = 2000; year <= 2500; year++){
    //     if(year % 4 == 0 && year % 100 != 0){
    //         printf("%d是闰年\n", year);
    //         continue;
    //     }
    //     if(year % 400 == 0){
    //         printf("%d是闰年\n", year);
    //         continue;
    //     }
    //     printf("%d不是闰年\n", year);
    // }
    // return 0;

    for(int year = 2000; year <= 2500; year++){
        if(year % 4 == 0 && year % 100 != 0){
            printf("%d是闰年\n", year);
        }
        else if(year % 400 == 0){
            printf("%d是闰年\n", year);
        }
        else
            printf("%d不是闰年\n", year);
    }
    return 0;
}
