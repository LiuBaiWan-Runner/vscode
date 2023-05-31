/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-31
 * @brief   :MT2152抽奖
 *          :
 *          :
 */
#include <iostream>

using namespace std;
#define int long long

int n, dp[40][160], sum1, sum2, fenmu = 1, temp;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
signed main()
{
    cin >> n;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= 4 * n; j++){
            for(int k = 1; k <= 4; k++){
                if(j > k){
                    dp[i][j] += dp[i -1][j -k];
                }
            }
        }
    }
    for(int i = n; i < 2 * n; i++){
        sum1 += dp[n][i];
    }
    for(int i = 3 * n + 1; i <= 4 * n; i++){
        sum2 += dp[n][i];
    }
    for(int i = 1; i <= n; i++){
        fenmu *= 4;
    }
    temp = gcd(sum1, fenmu);
    cout << sum1 / temp << "/" << fenmu / temp << endl;
    temp = gcd(sum2, fenmu);
    cout << sum2 / temp << "/" << fenmu / temp << endl;
    return 0;
}
