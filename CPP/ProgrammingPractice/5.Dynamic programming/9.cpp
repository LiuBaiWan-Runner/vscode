/*
* @file    :9.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :整数划分问题（C语言递归）
*          :https://blog.csdn.net/qq_43211132/article/details/84288719
*          :
*/
#include <stdio.h>
#include <stdlib.h>
int digui(int n,int m){
    if(m==1||n==1)
    {
        return 1;
    }
    else if(n<m)
    {
       return digui(n,n);
    }
    else if(n==m)
    {
        return (1+digui(n,n-1));
    }
    else if(n>m&&m>1)
    {
        return (digui(n,m-1)+digui(n-m,m));
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a;
    a=digui(n,n);
    // printf("划分总数为：%d种\n",a);
    printf("%d\n",a);
    return 0;
}