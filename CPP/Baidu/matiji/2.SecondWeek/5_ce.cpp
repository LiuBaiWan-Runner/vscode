/*
* @file    :5_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-10
* @brief   :MT2056二阶前缀和
*          :视频讲解例程
*          :
*/
#include <iostream>
#include <cstring>
using namespace std;
int coo[1010][1010], temp[1010][1010];
int main()
{
    int n, R,v, sum = 0;
    int x, y, maxX, maxY;
    cin >> n >> R;
    for(int i = 0; i<n; i++){
        cin >> x >> y >> v;
        if(x>maxX)  maxX = x;
        if(y>maxY)  maxY = y;
        coo[x++][y++] += v;
    }
    for(int i = 1; i<=1001; i++){
        for(int j = 1; j<1001; j++){
            temp[i][j] += temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1] + coo[i][j];
        }
    }
    for(int i = R; i<=1001; i++){
        for(int j = R; j<1001; j++){
            sum  = max(sum, temp[i][j] - temp[i-R][j] - temp[i][j-R] + temp[i-R][j-R]);
        }
    }
    cout << sum << endl;
    return 0;
}