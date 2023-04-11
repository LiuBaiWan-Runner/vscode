/*
* @file    :6_copy_3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :Dropping tests 二分（分数优化）
*          :https://blog.csdn.net/ALPS233/article/details/51558156
*          :
*/
#include<iostream>
#include<queue>
#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,k;
double a[1005],b[1005];
double y[1005];
double cmp(double a,double b)
{
    return a>b;
}
bool C(double x)
{

    double tmp=0;
    for(int i=1;i<=n;i++)
    {
        y[i]=a[i]-x*b[i];
    }
    sort(y+1,y+1+n,cmp);
    for(int i=1;i<=k;i++)
    {
        tmp+=y[i];
    } 

    if(tmp>=0) return 1;
    return 0;

} 
void solve()
{
    double l=0,r=1.0,mid;
    for(int i=0;i<100;i++)
    {
        mid=(l+r)/2;
        if(C(mid))
        {
            l=mid;
        }else  r=mid;
    }

    printf("%.0lf\n",(double)mid*100.0);
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(!n&&!k) return 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
        }

        for(int j=1;j<=n;j++)
        scanf("%lf",&b[j]);
        k=n-k;
        solve();
    }
    return 0;
}