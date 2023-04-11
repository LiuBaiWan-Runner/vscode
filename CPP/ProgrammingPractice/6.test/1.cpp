/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/qq_40732657/article/details/114024997
 *          :
 *          :
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int T,n,k;
bool f[50005];
void ready()
{
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>T; 
}
void read_in()
{
	memset(f,false,sizeof(f));
	k=0;f[0]=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		for(int j=k;j>=0;j--)
		  if(f[j] && j+a<=50000)
		  {
		  	f[j+a]=true;
		  	k=max(k,j+a); 
		  }
	}
	
}
int get_sum()
{
	for(int i=k/2,j=k/2;i>=0 && j<=k;i--,j++)
	{
		if(f[i])  return i;
		if(f[j])  return j;
	}
	return 0;
}
void work()
{
	read_in();
	int max_sum=get_sum();
	cout<<abs(k-2*max_sum)<<endl;
}
int main()
{ 
	ready();
	while(T--)
	  work();
	return 0;
}