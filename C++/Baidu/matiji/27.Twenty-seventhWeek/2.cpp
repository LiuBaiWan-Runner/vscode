/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-10-11
 * @brief   :MT2226抽奖概率
 *          :AC
 *          :
 */
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    double p = 1, ans = 0;
    for(int i = 1; i <= n; i++){
        p /= 2;
        ans += p / i;
    }
    printf("%.6lf\n", ans);
    return 0;
}
