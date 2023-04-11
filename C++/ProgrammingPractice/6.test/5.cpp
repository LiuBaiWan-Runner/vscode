/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/qq_45654306/article/details/105527598
 *          :
 *          :
 */

#include<iostream>
using namespace std;
int split(int n,int m)
{
    if(n==1||m==1)
        return 1;
    else if (n<m)
        return split(n,n);
    else if(n==m)
        return split(n,n-1)+1;
    else
        return split(n,m-1)+split(n-m,m);
}

int main()
{
    int n;
    cin>>n;
    cout<<split(n,n);
}

