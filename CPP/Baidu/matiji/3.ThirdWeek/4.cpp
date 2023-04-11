/*
* @file    :4.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-18
* @brief   :MT2065区间修改
*          :视频讲解方法
*          :AC
*/
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n+1];
    int sub[n+1];
    int pos = 0, neg = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        if(i > 1){
            sub[i] = a[i] - a[i-1];
        }
    }
    for(int  i = 2; i<=n; i++){
        if(sub[i] > 0){
            pos += sub[i];
        }
        else{
            neg += sub[i];
        }
    }
    cout << max(pos, -neg) << endl;

    return 0;
}
