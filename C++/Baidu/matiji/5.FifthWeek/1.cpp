/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-29
* @brief   :MT2105跳棋新编
*          :
*          :
*/
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n+2], temp[n+2];

    a[0] = 0, a[n+1] = 0;
    for(int i = 1; i<=n; i++){
        cin >>a[i];
    }

    int t = 1, ans = 0, tmp;
    temp[0] = 0;
    for(int i = 1; i<=n+1; i++){
        if(a[i] == 0 && (a[i-1] != 0 || a[i+1] != 0)){
            temp[t] = i;
            t++;
        }
    }
    temp[t] = n+1, temp[t+1] = n+1;
    int r, b;
    for(int i = 0; i<t; i++){
        r = 0;
        b = 0;
        for(int j = temp[i]; j<=temp[i+1]; j++){
            if(a[j] == 1){
                r++;
            }
            if(a[j] == 2){
                b++;
            }
        }
        tmp = min(r,b);
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
