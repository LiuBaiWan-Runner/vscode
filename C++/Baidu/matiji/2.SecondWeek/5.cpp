/*
* @file    :5.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-10
* @brief   :MT2056二阶前缀和
*          :直接全局遍历求解
*          :for层次太多，超时
*/
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll coo[1010][1010];
int main()
{
    memset(coo,0,sizeof(coo));
    int n, R;
    int x, y, maxX = 0, maxY = 0;
    ll v, maxSum = 0, tempSum = 0;
    cin >> n >> R;
    int Xcoo[n], Ycoo[n];
    for(int i = 0; i<n; i++){
        cin >> x >> y >> v;
        Xcoo[i] = x;
        Ycoo[i] = y;
        if(x>maxX)  maxX = x;
        if(y>maxY)  maxY = y;
        coo[x][y] += v;
    }
    
    // int i = 0;
    // for(int x : Xcoo){
    //     int y = Ycoo[i];
    //     if(x-R >= 0){
    //         for(int i = x-R+1; i < x+R; i++){
    //             if(y-R >= 0){
    //                 for(int j = y-R+1; j< y+R; j++){

    //                 }
    //             }
    //         }
    //     }
    // }


    for(int i = 1; i <= maxX; i++){ 
        for(int j = 1; j <= maxY; j++){
            tempSum = 0;
            // cout << coo[i][j] << ' ';    //try
            for(int k = i; k < i+R; k++){
                for(int l = j; l < j+R; l++){
                    tempSum += coo[k][l];
                }
            }
            if(tempSum > maxSum){
                maxSum = tempSum;
            }
        }
        // cout << endl;    //try
    }
    cout << maxSum << endl;
    return 0;
}
