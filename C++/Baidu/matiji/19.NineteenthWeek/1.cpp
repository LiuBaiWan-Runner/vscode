/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-09
 * @brief   :MT2176字符串构造
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 1e5 + 7;
int n, k, pi[N];
char s[N];

void prefix_function(char *s, int len){
    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
}

int main()
{
    cin >> n >> k >> s;
    prefix_function(s, n);
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n - pi[n - 1]; j++){
            cout << s[j];
        }
    }
    for(int i = n - pi[n - 1]; i < n; i++){
        cout << s [i];
    }
    return 0;
}
