/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :MT2088竹鼠中暑
*          :
*          :AC
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t, t+n);
    int temp = 0, sum = 0;
    for(int i = 0; i < n-1; i++){
        temp += t[i];
        sum += temp;
    }
    double ans = (double)sum/n;
    cout << setiosflags(ios::fixed) << setprecision(2) 
         << ans << endl;
    return 0;
}
