/*
* @file    :5_copy_3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :D - Expanding Rods
*          :https://www.cnblogs.com/dchnzlh/p/10427250.html#:~:text=When%20a%20thin%20rod%20of%20length%20L%20is,original%20rod%20being%20the%20chord%20of%20the%20segment.
*          :
*/
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<iostream>
#include<iomanip>
#define mset(a,b)   memset(a,b,sizeof(a))
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxn=1e5+10;
const int branch=26;
const int inf=0x7fffffff;
const double wc=1e-6;
const ll MOD=1e9+7;
double L,LL,n,c;
inline double f(double r)//半径对应的弧长
{
    double as=asin(L/(2.0*r));
    return 2.0*as*r;
}
double solve()
{
    double l=L/2.0,r=1e20,mid;//枚举半径R，求出在R下的弧长即可
    while(r-l>wc)
    {
        mid=(l+r)/2.0;
        if(f(mid)<LL)
            r=mid;
        else
            l=mid;
    }
    return (l+r)/2.0;
}
int main()
{
    while(scanf("%lf %lf %lf",&L,&n,&c))
    {
        if(L<0.0||n<0.0||c<0.0)
            break;
        if(n==0.0||c==0.0)
        {
             printf("0.000\n");
             continue;
        }
        LL=(1.0+n*c)*L;
        double ar=solve();//求出半径
        double as=asin(L/(2.0*ar));//求出此时的圆心角的一半
        cout<<fixed<<setprecision(3)<<ar*(1-cos(as))<<endl;
    }
    return 0;
}
