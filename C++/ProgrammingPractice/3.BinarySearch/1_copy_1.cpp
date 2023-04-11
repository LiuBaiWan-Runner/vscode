/*
* @file    :1_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :求下面方程的根：f(x) = x3- 5x2+ 10x - 80 = 0。
*          :https://blog.csdn.net/tigerisland45/article/details/106591374
*          :
*/
/* Bailian4140 方程求解 */

#include <iostream>
#include <cstdio>

using namespace std;

const double EPS = 1e-10;

double bs(double left, double right)
{
    double mid, f;
    while (right - left > EPS) {
        mid = left + (right - left) / 2;
        f = mid * mid * mid - 5 * mid * mid + 10 * mid - 80;
        if(f < 0) left = mid;
        else right = mid;
    }
    return mid;
}

int main()
{
    printf("%.9f\n", bs(5.0, 6.0));

    return 0;
}
