/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-10-11
 * @brief   :MT2223行列式
 *          :AC
 *          :
 */
#include <iostream>
using namespace std;
#define int long long
const int mod = 0x1f1f1f1f;

int T, n, a[10][10];

int sol(){
    int res = 1, w = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            while(a[i][i]){
                int di = a[j][i] / a[i][i];
                for(int k = i; k <= n; k++){
                    a[j][k] = (a[j][k] - di * a[i][k] % mod + mod) % mod;
                }
                swap(a[i], a[j]);
                w = -w;
            }
            swap(a[i], a[j]);
            w = -w;
        }
    }
    for(int i = 1; i <= n; i++){
        res = a[i][i] * res % mod;
    }
    res = w * res;
    return (res + mod) % mod;
}

signed main()
{
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        cout << sol() << endl;
    }
    return 0;
}
