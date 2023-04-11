/*
* @file    :4.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :https://blog.csdn.net/qq_43690454/article/details/104150384
*          :
*          :
*/

#include<bits/stdc++.h>
using namespace std;
int n; 
int k;
void mv(int j)
{
	printf("%d,%d-->%d,%d\n",j,j+1,k,k+1);
	k=j;
}
void dfs(int n)
{
	if(n==4)
	{
		mv(4);mv(8);mv(2);mv(7);mv(1);
	}
	else
	{
		mv(n);mv(2*n-1);dfs(n-1);
	}
}
int main()
{
	cin>> n;
	k=2*n+1;
	dfs(n);
} 


