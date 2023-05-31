/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-31
 * @brief   :MT2153异或和
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int  N = 1e5+7;
int n, a[N], dp[N];

int main()
{
    memset(dp,0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 550; j++){
            if(dp[j] < a[i]){
                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i <= 550; i++){
        if(dp[i]  != 0x3f3f3f3f){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int id : ans){
        cout << id << " ";
    }
    return 0;
}
