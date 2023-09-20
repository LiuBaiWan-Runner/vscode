/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2217数字游戏
 *          :
 *          :
 */

#include <iostream>

using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            ans ++;
            n /= i;
        }
    }
    if(n > 1){
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
