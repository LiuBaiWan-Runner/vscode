/*
* @file    :6.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :https://blog.csdn.net/weixin_45883286/article/details/105693309
*          :
*          :
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 1e5+10
using namespace std;
int n,a,add=500;
int dp[100][3000];
int main()
{
    scanf("%d",&n);
    dp[1][-1+add]=1;
    for(int i=2;i<=n-1;i++)
    {
        for(int j=-500;j<=n+add;j++)
        dp[i][j+add]=dp[i-1][j-i+add]+dp[i-1][j+i+add];
    }
    printf("%d",dp[n-1][n+add]);
    return 0;
}
