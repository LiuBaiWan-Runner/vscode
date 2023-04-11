/*
* @file    :15.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :切割回文 OpenJ_Bailian - 4122
*          :https://blog.csdn.net/a1097304791/article/details/90401782
*          :
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const int inf = 1<<30;
const LL maxn = 1010;

char s[maxn];
int dp[maxn]; //子串S[1-i]的最小切割回文
bool judge(int l, int r){
    while(l <= r){
        if(s[l] != s[r]) return false;
        ++l, --r;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf(" %s",s+1);
        int len = strlen(s+1);
        for(int i = 0; i <= len; ++i) dp[i] = inf;

        for(int i = 1; i <= len; ++i)
            for(int j = 1; j <= i; ++j)
                if(judge(j, i)){
                    if(j==1) dp[i] = 0; //S[1-i]的大回文
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
        printf("%d\n",dp[len]);
    }
	return 0;
}
