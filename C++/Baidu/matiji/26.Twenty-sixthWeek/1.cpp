/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2214元素共鸣
 *          :WA
 *          :
 */

#include <iostream>

using namespace std;

const int N = 1e4 + 7;
bool judge[N];
int prime[N], cnt;

int getPrimes(int n){
    for(int i = 2; i <= n; i++){
        if(!judge[i]){
            prime[cnt++] = i;
        }
        for(int j = 0; prime[j] * i <= n; j++){
            judge[prime[j] * i] == true;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int n, k;
    bool flag = false;
    cin >> n >> k;
    getPrimes(n);
    for(int i = 0; i < cnt; i++){
        int n1 = prime[i], n2 = n1 + k;
        if(n2 <= n && !judge[n2]){
            cout << n1 << " " << n2 << endl;
            flag = true;
        }
    }
    if(!flag){
        cout << "empty" << endl;
    }
    return 0;
}
