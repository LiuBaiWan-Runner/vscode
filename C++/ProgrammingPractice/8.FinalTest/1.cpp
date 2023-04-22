/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :
 *          :
 *          :
 */
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll a[n + 10], ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            if (abs(a[i] - a[j]) % 100 == 0 && !(a[i] == 0 && a[j] == 0) && a[i] != a[j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
