/*
* @file    :5_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :Expanding Rods（二分法）
*          :https://blog.csdn.net/qq_45856289/article/details/104545360
*          :
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-5;
double L,n,C;       //杆长，温度，热力系数
void binary()
{
    double bet;                 //延伸后杆中心到之前杆中心的距离
    double l=0.0,r=0.5*L;       //上下界，上界取0.5*L是因为方便而不是最小上界就是这个数
    double L1=(1+n*C)*L;        //变之后的杆长
    while(r-l>eps)              //因为定义的都是double型用r>l会死循环,所以加入精度
    {
        bet=(l+r)/2;
        double R=(4*bet*bet+L*L)/(8*bet);       //圆的半径
        if(2*R*asin(L/(2*R))<L1)
        {
            l=bet;
        }
        else
        {
            r=bet;
        }
    }
    printf("%.3lf\n",bet);
}
int main()
{
    while(cin>>L>>n>>C)
    {
        if(L<0&&n<0&&C<0)
        {
            break;
        }
        binary();
    }
    return 0;
}
