/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-07
 * @brief   :MT2163字符串构造2
 *          :
 *          :
 */
#include <iostream>

using namespace std;
#define int long long
const int mod = 1e9+7;
int f, n, dp[100005][2];
signed main()
{
    dp[1][0] = 0, dp[1][1] = 3;
    for(int i = 2; i <= 100000; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = 2 * (dp[i-1][0] + dp[i-1][1]) % mod;
    }
    cin >> f;
    while(f--){
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
    return 0;
}
