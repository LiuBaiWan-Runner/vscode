/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-26
 * @brief   :MT2106AB数对
 *          :
 *          :
 */
#include <iostream>
#include <map>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n, c, a[N];
ll ans;
map<int, int> mp;

int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
        a[i] -= c;
    }
    for(int i = 1; i <= n; i++){
        ans += mp[a[i]];
    }
    cout << ans << endl;
    return 0;
}
