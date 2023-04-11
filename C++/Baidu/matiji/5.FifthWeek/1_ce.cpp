/*
* @file    :1_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-30
* @brief   :MT2105跳棋新编
*          :棋子可以移动时，直接进行移动；
*          :不能移动即存在两个相邻且颜色不同的棋子，
*          :此时破换掉后边的棋子即可。
*          :AC
*/
#include <iostream>

using namespace std;


int main()
{
    int n, ans =0;
    cin >> n;
    int a[n+2];
    a[0] = 0, a[n+1] = 0;
    for(int i = 1; i<=n; i++){
        cin >>a[i];
    }
    for(int i = 2; i<=n; i++){
        if(a[i] && a[i-1] && a[i] != a[i-1]){
            a[i] = 0;
            ans++;
        }
    }
    cout << ans <<endl;
    return 0;
}
