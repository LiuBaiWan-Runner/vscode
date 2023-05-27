/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-24
 * @brief   :MT2149最长子段和
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 2e5 + 7;
int n, dp[N], ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dp[i];
    }
    ans = dp[1];
    for(int i = 2; i <= n; i++){
        if(dp[i - 1] >= 0){
            dp[i] = dp[i - 1] + dp[i];
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
