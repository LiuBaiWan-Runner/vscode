/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :https://blog.csdn.net/cqbz_lipengcheng/article/details/107584774
*          :
*          :
*/
#include <iostream>
#include <cstdio>
using namespace std;
int t, a[35][35][35][35], x1, _y, x2, y2;
//a[i][j][k][l]表示（i, j）与(k, l)有联系； 
int main() {
	scanf("%d", &t);
	for(int i = 1;i <= t; i++) {
		scanf("%d %d %d %d", &x1, &_y, &x2, &y2);
		x1 *= 2;_y *= 2;x2 *= 2;y2 *= 2;
		if(x1 + _y - x2 - y2 == 2) {
			//如果两点在同一水平线上 
			if(_y == y2) {
				//若竖着的一条线 
				a[x1 + 1][_y][x2][_y] = 1;
				a[x2][_y][x1 + 1][_y] = 1;//两点分别连一次 
				a[x1 + 1][_y][x1][_y] = 1;
				a[x1][_y][x1 + 1][_y] = 1;
			}
			if(x1  == x2) {
				a[x1][_y + 1][x1][y2] = 1;
				a[x1][y2][x1][_y + 1] = 1;
				a[x1][_y + 1][x1][_y] = 1;
				a[x1][_y][x1][_y + 1] = 1;
			}
		}
		if(x1 + _y - x2 - y2 == 2){
			if(_y == y2) {
				a[x1][_y][x2 + 1][_y] = 1;
				a[x2 + 1][_y][x1][_y] = 1;
				a[x2][_y][x2 + 1][_y] = 1;
				a[x2 + 1][_y][x2][_y] = 1;
			}
			if(x1  == x2) {
				a[x1][_y][x1][y2 + 1] = 1;
				a[x1][y2 + 1][x1][_y] = 1;
				a[x1][y2 + 1][x1][y2] = 1;
				a[x1][y2][x1][y2 + 1] = 1;
			}
		}
		if(x1 + _y - x2 - y2 == 4) {
			a[x1][_y][x2 + 1][y2 + 1] = 1;
			a[x2 + 1][y2 + 1][x1][_y] = 1;
			a[x2][y2][x2 + 1][y2 + 1] = 1;
			a[x2 + 1][y2 + 1][x2][y2] = 1;
		}
		if(x2 + y2 - x1 - _y == 4) {
			a[x1 + 1][_y + 1][x2][y2] = 1;
			a[x2][y2][x1 + 1][_y + 1] = 1;
			a[x1][_y][x1 + 1][_y + 1] = 1;
			a[x1 + 1][_y + 1][x1][_y] = 1;
		}
		if(x1 + _y == x2 + y2) {//连接对角线 
			a[x1][_y][(x2 + x1) / 2][(_y + y2) / 2] = 1;
			a[(x2 + x1) / 2][(_y + y2) / 2][x1][_y] = 1;
			a[x2][y2][(x2 + x1) / 2][(_y + y2) / 2] = 1;
			a[(x2 + x1) / 2][(_y + y2) / 2][x2][y2] = 1;
		}
		a[x1][_y][x2][y2] = 1;
		a[x2][y2][x1][_y] = 1;
	}
	for(int i = 0;i <= 18; i++) {
		for(int j = 0;j <= 18; j++) {
			for(int k = 0;k <= 18; k++) {
				for(int l = 0;l <= 18; l++) {
					for(int m = 0;m <= 18; m++) {
						for(int n = 0;n <= 18; n++) {
							if(a[i][l][j][m] == 1 && a[i][l][k][n] == 1 && !(i == j && l == m) && !(i == k && l == n)) {//判断两个点是不是同一个点 
								if((n - l) * (j - i) - (m - l) * (k - i) == 0) {//如果两点之间有通路 && 两点为一条直线即可连接 
									a[j][m][k][n] = 1;
									a[k][n][j][m] = 1;
								}
							}
						}
					}
				}
			}		
		}
	}
	int ans = 0;
	for(int i = 0;i <= 18; i++) {
		for(int j = 0;j <= 18; j++) {
			for(int k = 0;k <= 18; k++) {
				for(int l = 0;l <= 18; l++) {
					for(int m = 0;m <= 18; m++) {
						for(int n = 0;n <= 18; n++) {
							if(a[i][l][j][m] == 1 && a[i][l][k][n] == 1 && a[j][m][k][n] == 1 && !(i == j && l == m) && !(j == k && m == n) && !(i == k && l == n)) {//判断两个点是不是同一个点 
								if((n - l) * (j - i) - (m - l) * (k - i) != 0) {
									ans++;
								}
							}
						}
					}
				}
			}		
		}
	}
	printf("%d", ans / 6);
	return 0;
} 
