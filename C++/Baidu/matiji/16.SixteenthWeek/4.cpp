/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-14
 * @brief   :MT2170回文串
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 2e3 + 7;

int n, m, cost[N], dp[N][N];
char c, s[N];
int x, y;


int main()
{
    cin >> m >> n >> s + 1;
    while(m--){
        cin >> c >> x >> y;
        cost[c - 'a'] = min(x, y);
    }
    for(int r = 1; r <= n; r++){
        for(int l = r - 1; l >= 1; l--){
            if(s[l] == s[r]){
                dp[l][r] = dp[l + 1][r - 1];
            }
            else{
                dp[l][r] = min(dp[l + 1][r] + cost[s[l] - 'a'],
                                dp[l][r - 1] + cost[s[r] - 'a']);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
