/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-07
 * @brief   :MT2161Page
 *          :
 *          :
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long
const int N = 11;
ll f[N][10];

void init() {
    for(int i = 1; i < N; i++){
        f[i][0] = f[i - 1][9];
        for(int j = 1; j <= 9; j++){
        f[i][j] = j * pow(10, i - 1) + f[i][j - 1] + f[i][0];
        }
    }
}

ll dp(int x) {
    vector<int> num;
    int y = x;
    while(x){
        num.push_back(x % 10), x /= 10;
    }
    ll res = 0;
    for(int i = num.size() - 1; i >= 0; i--){
        int t =num[i];
        if(!t) continue;
        res += f[i + 1][t - 1] + (y % int(pow(10, i)) + 1) * t;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    init();
    cout << dp(n) << endl;
    return 0;
}
