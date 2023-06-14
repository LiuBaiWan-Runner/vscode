/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-14
 * @brief   :MT2169字符串转换
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 2007;
int dp[N][N];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size(), n = s2.size();
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= n; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
        }
    }
    cout << dp[m][n];
    return 0;
}
