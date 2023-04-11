/*
* @file    :4_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :二分查找水题--疯牛(POJ 2456)
*          :https://blog.csdn.net/qq_41661809/article/details/81105978
*          :
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
 
/* 疯牛问题
    最小距离最大化;
*/
const int MAX =100005 ;
int n , c ;
int L[MAX] ;
bool C(int x )
{
	int i ;
	int temp = L[0] ;
	int count = 1 ;
	for(i = 1 ; i < n ; i++)
	{
		if(L[i]-temp >=x)
		{
			temp = L[i] ;
			count ++ ;
			if(count >= c)
			return true ;
		}
 
	}
	
	return false ;
}
int Binary_Search()
{
	int left = 0 ;
	int right = L[n-1] - L[0] ;
	while(right >= left )
	{
		int mid = left + (right - left )/ 2 ;
		if(C(mid))
		{
			left = mid + 1 ;
		}
		else
		{
			right = mid - 1 ;
		}	
		
	}
	
	return left -1 ;
	
}
int main()
{
	int i ;
	while (scanf("%d%d",&n,&c)!=EOF)
	{
		for ( i= 0 ; i<n ; i++)
		{
			scanf("%d",&L[i]);
		}	
		sort(L,L+n);
		printf("%d\n",Binary_Search());
 
	}
	
	
	return 0 ;
}