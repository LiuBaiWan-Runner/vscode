/*
* @file    :1_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-05
* @brief   :MT2108外卖递送（距离和最小）
*          :视频讲解例程
*          :
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll a[n+1], ans = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i<=n;i++){
        ans += abs(a[n/2+1] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
