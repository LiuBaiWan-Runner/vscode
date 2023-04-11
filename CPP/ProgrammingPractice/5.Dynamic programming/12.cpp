/*
* @file    :12.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :dp算法 - poj 4120: 硬币
*          :https://www.cnblogs.com/zhangyue123/p/12559751.html
*          :
*/
#include <cstdio>
#include <cstring>

int dp[10010];
int ans[10010]; //ans数组表示在去掉a[i]币值之后，硬币能不能表示价格j
int a[200];
int b[200];

int main(){
    int n, x;
    int cnt;
    while(scanf("%d%d", &n, &x) != EOF){
        memset(dp, 0, sizeof(dp));
        memset(b, 0, sizeof(b));
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = x; j >= a[i]; j--){
                dp[j] += dp[j - a[i]];
            }
        }
        cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <=x; j++){
                if(j < a[i])
                    ans[j] = dp[j];
                else
                    ans[j] = dp[j] - ans[j - a[i]]; //这里理解有点困难，dp[j]表示可以包括a[i]也可以不包括a[i]，凑成j面值的方法数，ans[j-a[i]]表示不带a[i]可以凑成
                                                    // j-a[i] 的方法总数， j - a[i] + a[i]就是j，也就是ans[j - a[i]]是必须带上a[i]能凑成j 面值的方法总数，两者减就是不带上a[i] 凑成 j面值的方法数。
                    
            }
            if(ans[x] == 0){
                b[cnt ++] = a[i];
            }
        }
        printf("%d\n", cnt);
        if(cnt == 0)
            printf("\n\n");
        else
            for(int i = 0; i < cnt; i++){
                if(i != cnt -1)
                    printf("%d ",b[i]);
                else
                    printf("%d\n" , b[cnt - 1]);
            }
        
    }
}
