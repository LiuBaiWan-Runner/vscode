/*
 * @file    :example_2.4.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :1-1/2+1/3-1/4+···+1/99-1/100;
 *          :
 *          :
 */
#include <stdio.h>

int main(){
    int sign = 1;
    double sum = 1, term;
    for(double deno = 2; deno <= 100; deno++){
        sign *= -1;
        term = sign*(1/deno);
        sum += term;
    }
    printf("sum = %f",sum);
    return 0;
}