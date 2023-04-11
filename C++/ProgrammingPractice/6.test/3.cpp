/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :题目：https://blog.csdn.net/max_kibble/article/details/55050618
 *          :AC代码：https://blog.csdn.net/hei_nero/article/details/10418835
 *          :
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define clr(a,b) memset(a,b,sizeof(a))
 
const int INF = 0x3f3f3f3f;
int n,t,m;
int dp[510][510];
 
int main() {
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d%d", &n, &t, &m);
        clr(dp,0);
        int d;
        REP(i,1,n+1) {
            scanf("%d", &d);
            getchar();
            for(int j = m; j > 0; j --) {
                for(int k = t; k > 0; k --) {
                    if(d <= k) {
                        dp[j][k] = max(dp[j][k], dp[j][k-d] + 1);
                        dp[j][k] = max(dp[j][k], dp[j-1][t] + 1);
                    }
                }
            }
        }
        printf("%d\n", dp[m][t]);
        if(cas) printf("\n");
    }
    return 0;
}