/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-24
 * @brief   :MT2144上楼梯
 *          :
 *          :
 */
#include <iostream>

using namespace std;

int n, m, num;
long long dp[100];

int main()
{
    cin >> m >> n;
    num = (n-1) * m;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= num; i++)
        dp[i] = dp[i -1] + dp[i - 2];
    cout << dp[num];
    return 0;
}
