/*
* @file    :6_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :POJ - 2976 D - Dropping tests(二分查找+01分数规划搜索)
*          :https://blog.csdn.net/qq_41037114/article/details/83023431
*          :
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
double a[1050],b[1050],c[1050];
const double eps=1e-7;
int n,m;
 
bool cmp(const double &x,const double &y)
{
	return x>y;
}
 
bool ok(double x)
{
	for(int i=1;i<=n;i++)
		c[i]=a[i]-b[i]*x;
	sort(c+1,c+n+1,cmp);
	double sum=0;
	for(int i=1;i<=n-m;i++) sum+=c[i];
	if(sum>0) return 1;
	else return 0;
}
 
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lf",&b[i]);
		double l=0.0,r=1.0;
		double ans=0;
		while(r-l>=eps)
		{
			double mid=(l+r)/2.0;
			if(ok(mid))
			{
				l=mid;
				ans=mid;
			}
			else r=mid;
		}
		printf("%.0f\n",ans*100);
	}
	return 0;
}