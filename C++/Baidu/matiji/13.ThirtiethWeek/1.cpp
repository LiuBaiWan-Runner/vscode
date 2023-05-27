/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-24
 * @brief   :MT2146大厨小马哥
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int x, n, m, k;
long long dp[N];

int main()
{
    cin >> x >> n >> m >> k;
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        if(i - n >= 0)
            dp[i] += dp[i - n];
        if(i - m >= 0)
            dp[i] += dp[i - m];
        if(i - k >= 0)
            dp[i] += dp[i - k];
        dp[i] = dp[i] % mod;
    }
    if(dp[x])
        cout << dp[x];
    else
        cout << "impossible";
    return 0;
}
