/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-07
 * @brief   :MT2159赶deadline
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 1e4 + 7;
int T, n, w[N], v[N], dp[N], path[N][N], ans[N];

int main()
{
    cin >> n >> T;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    } 
    for(int i = 1; i <= n; i++){
        for(int j = T; j >= w[i]; j--){
            if(dp[j - w[i]] + v[i] > dp[j]){
                dp[j] = dp[j - w[i]] + v[i];
                path[i][j] = 1;
            }
        }
    }
    cout << dp[T] << endl;
    int i = n, j = T, cnt = 0;
    while (i >= 1 && j){
        if(path[i][j]){
            ans[cnt++] = i;
            j -=w[i];
        }
        i--;
    }
    for(int k = cnt - 1; k >= 0; k--){
        cout << ans[k] << " ";
    }
    return 0;
}
