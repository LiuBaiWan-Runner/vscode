/*
* @file    :5_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :expanding rod(二分+数学公式)
*          :https://blog.csdn.net/weixin_43438700/article/details/89841047
*          :
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps=1e-5;
double l,n,c,L;
bool judge(double x){
    double r=(l*l+4*x*x)/8/x;
    double s=2*r*asin(l/2/r);
    return s>=L;

}
int main(){

    while(~scanf("%lf%lf%lf",&l,&n,&c)&&(l>=0||n>=0||c>=0)){
    L=(1+n*c)*l;
    double left=0,right=l/2,mid;
    while(right-left>eps){
        mid=(right+left)/2;
        if(judge(mid)) right=mid;
        else left=mid;

    }
    printf("%.3f\n",right);}
    return 0;
}

