/*
* @file    :14.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :dp算法 - poj 4121:股票买卖
*          :https://www.cnblogs.com/zhangyue123/p/12565028.html
*          :https://blog.csdn.net/zqhf123/article/details/105859650
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

int st[100010];
int dp1[100010]; //dp1表示前i天最大收益
int dp2[100010]; //dp2表示后i天最大收益

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(st, 0, sizeof(st));
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        int n;
        scanf("%d", & n);
        for(int i = 0; i < n; i++){
            scanf("%d", &st[i]);
        }
        
        int minn = st[0];
        int maxn = st[n-1];
        for(int i = 1; i < n; i++){
            if(st[i] < minn)
                minn = st[i];
            dp1[i] = std:: max(dp1[i-1], st[i] - minn);
        }
        for( int i = n - 2; i>=0 ; i--){
            if(st[i] > maxn)
                maxn = st[i];
            dp2[i] = std:: max(dp2[i+1], maxn - st[i]);
        }
        
        int max = 0;
        for(int i = 0; i < n; i++){
            if(dp1[i] + dp2[i] > max)
                max = dp1[i] + dp2[i];
        }
        printf("%d\n", max);
        
    }
    return 0;
}
