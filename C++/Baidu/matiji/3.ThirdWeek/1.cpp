/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-17
* @brief   :MT2053信号灯
*          :前缀和 差分
*          :AC
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int main()
{
    int N, K, B, temp, ans;
    cin >> N >> K >> B;
    ans = B;
    int a[N+10], sum[N+10];
    memset(a,0,sizeof(a));
    sum[0] = 0;
    for(int i = 1; i<=B; i++){
        cin >> temp;
        a[temp] = 1;
    }
    for(int i = 1; i<=N; i++){
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i+K-1 <= N; i++){
        ans = min(ans, sum[i + K -1] - sum[i-1]);
    }
    cout << ans << endl;
    return 0;
}
