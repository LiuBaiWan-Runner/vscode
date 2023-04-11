/*
 * @file    :9.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/yanweiqi1754989931/article/details/109247649
 *          :
 *          :
 */
#include <iostream>
#define xa x + a[i]
#define yb y + b[i]
using namespace std;

int m, n, x, y, cnt = 0;
const int a[]={1,2,2,1,-1,-2,-2,-1};
const int b[]={2,1,-1,-2,-2,-1,1,2};
bool g[10][10];

void dfs(int x, int y, int dc){
    if(dc == 0){
        cnt ++;
        return;
    }
    g[x][y] = true;
    for(int i = 0; i < 8; i++){
        if(xa >= 0 && xa < m && yb >= 0 && yb < n && !g[xa][yb]) 
            dfs(xa, yb, dc - 1);
    }
    g[x][y] = false;
}

int main(){
    int t = 0; 
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        dfs(x, y, n * m - 1);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}
