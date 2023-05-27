/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-24
 * @brief   :MT2147纸袋
 *          :
 *          :
 */
#include <iostream>

using namespace std;
#define ll long long
const int N = 4e6 + 5;

int n, mod;
ll dp[N], sum[N];

int main()
{
    cin >> n >> mod;
    dp[n] = sum[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = sum[i + 1];
        for (int j = 2; j * i <= n; j++)
        {
            int r = min(n, i * j + j - 1);
            dp[i] = (dp[i] + sum[i * j] - sum[r + 1]) % mod;
        }
        sum[i] = (sum[i+1] + dp[i]) % mod;
    }
    cout << dp[1];
    return 0;
}
