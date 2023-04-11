/*
* @file    :13.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :动态规划——1292：宠物小精灵之收服（二维背包问题）
*          :https://blog.csdn.net/qq_45700119/article/details/123758071
*          :
*/
#include<bits/stdc++.h>
#define N 1010
#define INF 0x3f3f3f3f
using namespace std;

int n,m,k,w[N],c[N],dp[N][N];
//w[i]数组为收服第i个精灵所需精灵球的数量 
//c[i]数组为收服第i个精灵所需收到的伤害 
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>w[i]>>c[i];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++){
		for(int j=n;j>=w[i];j--){
			for(int k=m;k>=c[i];k--){
				dp[j][k]=max(dp[j][k],dp[j-w[i]][k-c[i]]+1);
			}
		}
	}
	for(int i=0;i<=m;i++){
		if(dp[n][m]==dp[n][i]){
			cout<<dp[n][m]<<" "<<m-i;
			break;
		}
	}
	return 0;
}