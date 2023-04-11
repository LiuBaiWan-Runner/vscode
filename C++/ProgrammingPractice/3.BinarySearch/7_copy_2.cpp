/*
* @file    :7_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :UVA 10341- Solve It(二分+精度求解方程值)
*          :https://blog.csdn.net/u013486414/article/details/43527335
*          :
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define eps 1e-8
double p,q,r,s,t,u;
double Solve (double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;//exp(x) 指的是e的x次方。
}
int main()
{
    double left,right,mid;
    while(~scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)) {
        if(Solve(0)<0||Solve(1)>0)
            printf("No solution\n");
        else {
            left=0;
            right=1;
            while((right-left)>=eps) {
                mid=(left+right)/2;
                if(Solve(mid)<0)
                    right=mid;
                else
                    left=mid;
            }
            printf("%.4lf\n",mid);
        }
    }
    return 0;
}