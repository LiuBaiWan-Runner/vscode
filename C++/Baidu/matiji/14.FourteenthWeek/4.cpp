/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-31
 * @brief   :MT2156矩阵取数
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
using namespace std;
int n, m, mod, ans, INF = 0x3f3f3f3f;
int a[75][75], dp[75][75][75];

int main()
{
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, -INF, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if(j == 1){
                for(int k = 0; k <= m / 2; k++){
                    for(int l = 0; l < mod; l++){
                        dp[i][0][l] = max(dp[i][0][l], dp[i - 1][k][l]);
                    }
                }
            }
            for(int k = m / 2 - 1; k >= 0; k--){
                for(int l = 0; l < mod; l++){
                    dp[i][k + 1][(l + a[i][j]) % mod] = 
                    max(dp[i][k + 1][(l + a[i][j]) % mod],
                        dp[i][k][l] + a[i][j]);
                }
            }
        }
    }
    for(int j = 0; j <= m/2; j++){
        ans = max(ans, dp[n][j][0]);
    }
    cout << ans << endl;
    return 0;
}
