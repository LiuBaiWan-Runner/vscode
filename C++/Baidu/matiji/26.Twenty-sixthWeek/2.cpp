/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2215小马哥喜欢的数
 *          :AC
 *          :
 */

#include <iostream>

using namespace std;

const int N = 1e7 + 7;
int T, x, ans[N], nxt[N], cnt;
bool judge[N] = {1};

bool check(int x){
    while(x){
        if(x % 10 == 7){
            return true;
        }
        x /= 10;
    }
    return false;
}

int getNums(int n){
    int curr = 1;
    for(int i = 2; i <= n; i++){
        if(!judge[i]){
            bool flag = check(i);
            if(!flag){
                ans[cnt++] = i;
                nxt[curr] = i;
                curr = i;
            }
            else{
                for(int j= i; j <= n; j += i){
                    judge[j] = true;
                }
            }
        }
    }
    return 0;
}

int main()
{
    getNums(N);
    cin >> T;
    while(T--){
        cin >> x;
        if(judge[x]){
            cout << -1 << endl;
        }
        else{
            cout << nxt[x] << endl;
        }
    }
    return 0;
}
