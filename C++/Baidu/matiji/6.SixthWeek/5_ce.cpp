/*
* @file    :5_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-05
* @brief   :MT2107活动分组(排序)
*          :
*          :
*/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n, temp;
    cin >> n;
    int a[n+1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> temp;
        a[i] -= temp;
    }
    sort(a+1,a+n+1);
    for(int i = 1; i<=n/2; i++){
        if(a[i] != -a[n-i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
