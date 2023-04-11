/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :MT2055最大异或和
*          :异或前缀和，循环暴力求解  可以尝试动态规划
*          :AC
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, sum;
    cin >> n;
    int w[n+1], t[n+1];
    // t[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> w[i];
        t[i] = w[i]^t[i-1];
        // for(int j = i; j<=n; j++){
        //     sum = max(sum, t[j]^t[i-1]);
        // }
    }
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            sum = max(sum, t[j]^t[i-1]);
        }
    }
    cout << sum << endl;
    
    return 0;
}
