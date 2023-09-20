/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2213质数率
 *          :WA
 *          :
 */

#include <iostream>

using namespace std;
const int N = 1e8 + 7;
bool judge[N];
int prime[N], cnt, n;

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
    cin >> n;
    getPrimes(n);
    printf("%.3lf\n", (double)cnt / n);
    return 0;
}
