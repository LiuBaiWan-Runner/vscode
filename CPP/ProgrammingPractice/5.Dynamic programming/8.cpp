/*
* @file    :8.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :POJ1037————A decorative fence（动态规划）
*          :https://blog.csdn.net/say_c_box/article/details/60322057
*          :
*/
// test.cpp : 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
 
typedef long long ll;
 
int t, n;
ll c;
ll dp[25][25][2];
void init() {
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j; k < i; k++) {
				dp[i][j][0] += dp[i - 1][k][1];
			}
			for (int k = 1; k < j; k++) {
				dp[i][j][1] += dp[i - 1][k][0];
			}
		}
	}
}
int res[25];
int vis[25];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &c);
		init();
		memset(res, 0, sizeof(res));
		memset(vis, 0, sizeof(vis));
		int no=0;
		ll s = 0;
  		for (int cur = 1; cur <= n; cur++) {
			no = 0;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) {
					++no;
					ll num=0;
					if (cur == 1)
						num = dp[n][no][0] + dp[n][no][1];
					else {
						if (i > res[cur - 1] && (cur <= 2 || res[cur - 2]>res[cur - 1])) {
							num += dp[n-cur+1][no][1];
						}
						else if(i<res[cur-1] && (cur <= 2 || res[cur - 2]<res[cur - 1])){
							num += dp[n-cur+1][no][0];
						}
					}
					s += num;
					if (s >= c) {
						s -= num;
						res[cur] = i;
						vis[i] = 1;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", res[i], i == n ? '\n' : ' ');
		}
	}
}