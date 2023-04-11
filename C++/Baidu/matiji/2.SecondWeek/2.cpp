/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :MT2067 n*n房间铺m块地毯
*          :暴力循环
*          :AC
*/
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    int room[n][n];
    memset(room,0,sizeof(room));
    int x1, y1, x2, y2;
    for(int i = 0; i<m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1-1; j<=x2-1; j++){
            for(int k = y1-1; k<=y2-1; k++){
                room[j][k]++;
            }
        }
    }
    for(int j = 0; j<n; j++){
        for(int k = 0; k<n; k++){
            cout << room[j][k];
            if(k<n-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}
