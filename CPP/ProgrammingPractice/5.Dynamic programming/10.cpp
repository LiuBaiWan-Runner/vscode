/*
* @file    :10.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :第九章 动态规划-1296：开餐馆
*          :https://blog.csdn.net/zqhf123/article/details/105768472
*          :
*/
#include<cstdio>
#include<iostream>
#define N 1001
#define INF 0X3F3F3F3F
using namespace std;
int w[N],c[N],f[N];
int main(){
	int T;
	cin >> T;//测试数据组数
	while(T--)//每测试一直 减去-次
	{
		int n,k;
		cin >> n >> k; //输入总数n和距离限制K
		for(int i = 1; i <= n; i++)
		cin >> w[i];   // n 个地点位置
		for(int i = 1; i <= n ; i++)
		{
			cin >> c[i];// n个地点的餐馆利润
			f[i] = c[i];
		}
		for(int i = 1; i<= n; i++)
		  for(int j = 1; j <= n; j++)
		   if(w[i] - w[j] > k)//餐馆之间的距离必须大于k
		   f[i] = max(f[i],f[j] + c[i]);//f[i]表示前i个地点开餐馆的最大利润
	int maxx = -INF;//初值无限小
	for(int i = 1; i <= n; i++)//再求利润最大值
	 maxx = max(f[i], maxx);
	cout << maxx << endl;
}
	return 0;
}
