/*
* @file    :2_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/qq_30277239/article/details/104389629
*          :
*          :
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10,M = 16;
int n;
double X,s[N][N],f[N][N][N][N][M];
double get(int x1,int y1,int x2,int y2){
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}
double dfs(int x1,int y1,int x2,int y2,int k){
    double &v = f[x1][y1][x2][y2][k];
    if(v >= 0)  return v;
    if(k == 1){
        double s = get(x1,y1,x2,y2) - X;
        return v = s * s / n;
    }
    v = 1e9;
    for(int i = x1;i < x2;i++){
        double s1 = get(i + 1,y1,x2,y2) - X,s2 = get(x1,y1,i,y2) - X;
        v = min(v,dfs(x1,y1,i,y2,k-1) + s1 * s1 / n);
        v = min(v,dfs(i + 1,y1,x2,y2,k-1) + s2 * s2 / n);
    }
    for(int i = y1;i < y2;i++){
        double s1 = get(x1,i + 1,x2,y2) - X,s2 = get(x1,y1,x2,i) - X;
        v = min(v,dfs(x1,y1,x2,i,k-1) + s1 * s1 / n);
        v = min(v,dfs(x1,i + 1,x2,y2,k-1) + s2 * s2 / n);
    }
    return v;
}
int main(){
    cin>>n;
    for(int i = 1;i <= 8;i++){
        for(int j = 1;j <= 8;j++){
            cin>>s[i][j];
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
    X = s[8][8] / n;
    memset(f,-1,sizeof f);
    printf("%.3lf\n",sqrt(dfs(1,1,8,8,n)));
    return 0;
}