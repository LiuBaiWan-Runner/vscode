/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-10-11
 * @brief   :MT2225小码哥的抽卡之旅
 *          :AC
 *          :
 */
#include <iostream>

using namespace std;

int n;
double x[97], ans;

int main()
{
    cin >> n;
    x[1] = 1;
    for(int i = 2; i <= n; i++){
        x[i] = x[i - 1] * 0.994;
    }
    for(int i = 1; i <= n; i++){
        ans += x[i] * 0.006;
    }
    ans *= 100;
    if(n == 90){
        ans = 100;
    }
    printf("%.6f\%\n", ans);
    return 0;
}
