/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :MT2089逃课
*          :
*          :
*/
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    long long a[n][2];
    int t[n];
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = t[i-1]; j < n; j++){
            if(a[j][0] == i && a[j][1] > temp){
                temp = a[j][1];
                t[i] = j;
            }
        }
        a[t[i]][1] = 0;
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i][0] << ' ' << a[i][1] << endl;
    // }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i][1];
    }
    cout << sum <<endl;
    return 0;
}
