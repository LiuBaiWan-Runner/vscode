/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :The Triangle POJ - 1163 (动态规划经典入门题)
*          :https://blog.csdn.net/alex1997222/article/details/88918842
*          :
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
//输入数字
int N;
int triArr[MAXN][MAXN];
int stDp[MAXN][MAXN];
 
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triArr[i][j];   //输入结果
		}
	}
 
	//先把第一阶段的结果进行填充
	for (int k = 0; k < N; ++k) {
		stDp[N - 1][k] = triArr[N - 1][k];  //填充的结果是最后一行
	}
 
	for (int i = N - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			stDp[i][j] = max(stDp[i+1][j], stDp[i+1][j + 1]) + triArr[i][j];
		}
	}
	cout << stDp[0][0] << endl;
 
	// system("PAUSE");
	return 0;
}