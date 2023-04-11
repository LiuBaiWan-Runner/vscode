/*
 * @file    :example_2.5.c
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :判断是否为素数(prime number)[2, sqrt(n)]
 *          :
 *          :
 */

#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            printf("%d不是素数", n);
            return 0;
        }
    }
    printf("%d是素数", n);
    return 0;
}
