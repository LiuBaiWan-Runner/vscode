/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-07
 * @brief   :MT2160写程序
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 507;
int a[N], dp[N][N], n, m, b, mod, ans;

int main()
{
    cin >> n >> m >> b >> mod;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = a[i]; k <= b; k++){
                dp[j][k] = (dp[j][k] + dp[j-1][k-a[i]]) % mod;
            }
        }
    }
    for(int i = 0; i <= b; i++){
        ans = (ans + dp[m][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}
