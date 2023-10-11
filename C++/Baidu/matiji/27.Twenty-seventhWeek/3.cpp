/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-10-11
 * @brief   :MT2224矩阵乘法 
 *          :AC
 *          :
 */
#include <iostream>

using namespace std;
int l, m, n, a[1010][1010], b[1010][1010];

int main()
{
    cin >> l >> m >> n;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= n; j++){
            int x = 0;
            for(int k = 1; k <= m; k++){
                x += a[i][k] * b[k][j];
            }
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
