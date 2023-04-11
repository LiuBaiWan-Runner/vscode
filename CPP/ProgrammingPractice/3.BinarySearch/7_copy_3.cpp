/*
* @file    :7_copy_3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :Solve It UVA - 10341
*          :https://blog.csdn.net/we1215053460/article/details/78806669
*          :
*/
#include<stdio.h>
#include<math.h>
 
int p,q,r,s,t,u;
 
double check(double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
 
int main()
{
    while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u))
    {
        double high=1,low=0,mid;
        while(high-low>1e-8)
        {
            mid=(high+low)/2;
            if(check(mid) > 0)
                low=mid;
            else
                high=mid;
        }
        if(fabs(check(mid)-0.0)<1e-6)
            printf("%.4f\n",mid);
        else
            printf("No solution\n");
    }
    return 0;
}