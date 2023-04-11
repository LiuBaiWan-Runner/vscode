/*
* @file    :4_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-05
* @brief   :MT2106布阵指挥（排序）
*          :视频讲解例程
*          :
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
    int a[n+1], b[n+1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    b[1] = a[1];
    for(int i = 2; i<=n; i++){
        sort(a+1,a+i);
        for(int j = 1; j<i; j++){
            if(fabs(a[i]-a[j]) < x){
                a[i] = a[j]+x;
                b[i] = a[i];
            }
            else{
                b[i] = a[i];
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
