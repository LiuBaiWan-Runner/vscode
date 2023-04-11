/*
* @file    :6_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :POJ-2976Dropping tests
*          :https://www.cnblogs.com/Dawn-Star/p/9610410.html
*          :
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <cmath>
#include <time.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define ms(a,b) memset(a,b,sizeof(a))

typedef long long ll;

const double eps=1e-7;

int n,k;
double a[1010],b[1010],d[1010];

inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}

int main()
{
	while (1)
	{
		n=read(),k=read();
		if (n==0 && k==0) break;
		for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
		for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
		double l=0.0,r=1.0,mid;
		while (r-l>eps)
		{
			mid=(l+r)/2;
			for (int i=1;i<=n;i++) d[i]=a[i]-mid*b[i];
			sort(d+1,d+1+n);
			double sum=0.0;
			for (int i=k+1;i<=n;i++) sum+=d[i];
			if (sum>0) l=mid;
			else r=mid;
		}
		printf("%.0f\n",mid*100);
	}
	return 0;
}
