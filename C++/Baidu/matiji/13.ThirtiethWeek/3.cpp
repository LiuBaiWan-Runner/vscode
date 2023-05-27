/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-24
 * @brief   :MT2150旅费
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 1e3 + 7;
int a[N][N], dp[N], n;

int main()
{
    cin >> n;
    n++;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> a[i][j];
        }
        dp[i] = 0x3f3f3f3f;
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j <= n; j++){
            dp[i] = min(dp[i], a[i][j] + dp[j]);
        }
    }
    cout << dp[0];
    return 0;
}
