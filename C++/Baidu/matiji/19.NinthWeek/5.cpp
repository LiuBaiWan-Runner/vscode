/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-09
 * @brief   :MT2178最漂亮的工艺品
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 3e5 + 7;
int n, a[N], ans;

int func(int *a, int n){
    int k = 0, i =0, j = 1;
    while(k < n && i < n && j < n){
        if(a[(i + k) % n] == a[(j + k) % n]){
            k++;
        }
        else{
            a[(i + k) % n] > a[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if(i == j){
                i++;
            }
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ans = func(a, n);
    for(int i = 0; i < n; i++){
        cout << a[(ans + i) % n] << ' ';
    }
    return 0;
}
