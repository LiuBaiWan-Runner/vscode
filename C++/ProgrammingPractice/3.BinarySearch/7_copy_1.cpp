/*
* @file    :7_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :UVA - 10341 Solve It (二分)
*          :https://blog.csdn.net/zhao5502169/article/details/79829997
*          :
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
double p,q,r,s,t,u;
const double eps = 1e-7;
double E = exp(1);
double Get(double x){
    double res = p*pow(E,-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x + u;
    return res;
}
int main(void){
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u) != EOF){
        double l = 0,r = 1;
        if(Get(0) < 0 || Get(1) > 0){
            printf("No solution\n");
            continue;
        }
        while(r - l - eps >  0){
            double mid = (l+r)/2;
            double res = Get(mid);
            if(res > eps){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        printf("%.4lf\n",l);
    }
    return 0;
}