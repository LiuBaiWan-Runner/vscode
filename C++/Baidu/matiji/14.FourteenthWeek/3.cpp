/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-31
 * @brief   :MT2154海龟
 *          :
 *          :
 */
#include <iostream>

using namespace std;
#define int long long
string s;
int dp[101][51][2], n, INF = 0x3f3f3f3f;
signed main()
{
    cin >> s >> n;
    int size = s.size();
    s = ' ' + s;
    for(int i = 0; i <= size; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j][0] = dp[i][j][1] = -INF;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1; i <= size; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= j; k++){
                if(s[i] == 'F'){
                    if(k % 2 == 1){
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0]);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
                    }
                    else{
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
                        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
                    }
                }
                else if(k % 2 == 1){
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
                }
                else{
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][1]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
                }
            }
        }
    }
    cout << max(dp[size][n][0], dp[size][n][1]);
    return 0;
}
