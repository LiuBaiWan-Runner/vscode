/*
 * @file    :9.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/zqhf123/article/details/105859650
 *          :
 *          :
 */

#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N =100000+5;
int f[N];
int a[N];
int maxx[N];//存放到目前为止最大值
int minn[N];//存放到目前为止最小值
int n;
int i,j,T;
int ans;
 
void initial()
{
    for(i = 1;i <= n;i++)
        scanf("%d",a+i);
    return ;
}
 
int main()
{
    int f2[N];//i----n差的最大值
    int f1[N];//1---i差的最大值
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        initial();
 
        ans = -INF;
        minn[1] = a[1];
        f1[1] = 0;
        for(i = 2;i <= n;i++)
        {
            minn[i] = min(minn[i-1],a[i]);
            f1[i] = max(f1[i-1],a[i]-minn[i]);
        }
 
        maxx[n] = a[n];
        f2[n] = 0;
        for(i = n-1;i >= 1;i--)
        {
            maxx[i] = max(maxx[i+1],a[i]);
            f2[i] = max(f2[i+1],maxx[i]-a[i]);
        }
 
        for(i = 1;i <= n;i++)//选取交接点
            if(ans < f2[i]+f1[i])
                ans = f2[i]+f1[i];
 
        printf("%d\n",ans);
    }
 
    return 0;
 
}

