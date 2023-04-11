/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-17
* @brief   :MT2054背军理
*          :前缀和
*          :AC
*/
#include <iostream>

using namespace std;


int main()
{
    int n, q;
    cin >> n;
    int a[n+1], sum[n+1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    cin >> q;
    int x, y;
    for(int i = 0; i<q; i++){
        cin >> x >> y;
        cout << sum[y] - sum[x-1] <<endl;
    }
    return 0;
}
