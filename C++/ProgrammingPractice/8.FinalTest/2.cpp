/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
char s[100];
int main()
{
    int k;
    cin >> k;
    ll ans = 1;
    int i = 1;
    while(i < k){
        if(k <= 10){
            ans = k;
            break;
        }
        snprintf(s, sizeof(s), "%lld", ans);
        int len = sizeof(s);
        for(int i = 0; i < len-1; i++){
            if(abs(s[i]-s[i+1]) > 1){
                break;
            }
            if(i == len -2){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
