/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-05
* @brief   :MT2076处理订单
*          :视频讲解例程修改：9分
*          :
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6+10;
int n, m, ans;
int r[N], d[N], s[N], t[N], sub[N], need[N];
bool check(int num){
    memset(sub, 0, sizeof(sub));
    for(int i = 1; i<=num; i++){
        sub[s[i]] += d[i];
        sub[t[i]+1] -= d[i];
    }
    for(int i = 1; i <= n; i++){
        need[i] = need[i-1] + sub[i];
        if(need[i]>r[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> r[i];
    }
    for(int i = 1; i<=m; i++){
        cin >> d[i] >> s[i] >> t[i];
    }

    int left = 1, right = m, mid;
    if(check(m)){
        cout << 0 << endl;
        return 0;
    }
    while(left <= right){
        mid = left + (right-left)/2;
        if(!check(mid+1)){
            right = mid-1, ans = mid+1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << -1 << endl;
    cout << ans << endl;
    return 0;
}
