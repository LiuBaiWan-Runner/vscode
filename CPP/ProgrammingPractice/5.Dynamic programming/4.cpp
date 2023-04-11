/*
* @file    :4.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :Charm Bracelet（POJ-3624）
*          :https://blog.csdn.net/u011815404/article/details/80850564
*          :
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 100001
#define MOD 123
#define E 1e-6
using namespace std;
int c[N];
int w[N],d[N];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
            scanf("%d%d",&w[i],&d[i]);
 
        for(int i=1;i<=n;i++)
            for(int j=m;j>=w[i];j--)
                c[j]=max(c[j],c[j-w[i]]+d[i]);
 
        printf("%d\n",c[m]);
    }
    return 0;
}