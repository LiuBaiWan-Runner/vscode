/*
* @file    :3_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :C - 4 Values whose Sum is 0
*          :https://blog.csdn.net/weixin_37483932/article/details/76084941
*          :
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include<iostream>
using namespace std;
int ab[4010*4010],cd[4010*4010];
int main()
{
 
	int n,i,k,j,count,a[4010],b[4010],c[4010],d[4010];
	while(cin>>n)
	{
 
		for(i=0;i<n;i++)
			cin>>a[i]>>b[i]>>c[i]>>d[i];
		int cot1=0;
		int cot2=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ab[cot1++]=a[i]+b[j];
				cd[cot2++]=-(c[i]+d[j]);
			}
		}
		sort(cd,cd+cot2);
		count=0;
		for(i=0;i<cot1;i++)
		{
			int left=0;
		    int right=n*n-1;
			while(left<=right)
			{
				int mid=(left+right)/2;
				if(ab[i]==cd[mid])
				{
					count++;
					for(k=mid+1;k<cot2;k++)
					{
						if(ab[i]==cd[k])
							count++;
						else
							break;
					}
					for(k=mid-1;k>=0;k--)
					{
						if(ab[i]==cd[k])
							count++;
						else
							break;
					}
					break;
				}
				else if(ab[i]<cd[mid])
					 right=mid-1;
				else
					 left=mid+1;
 
			}
		}
		cout<<count<<endl;
	}
	return 0;
}