/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2216数的自我
 *          :AC
 *          :
 */

#include <iostream>

using namespace std;

const int N = 1e7 + 7;
int ans[N], cnt, n, k;
bool judge[N];

int cal(int x){
    int ans = x;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int getNums(int n){
    for(int i = 1, temp; i <= n; i++){
        temp = cal(i);
        if(temp <= n){
            judge[temp] = true;
        }
        if(!judge[i]){
            ans[cnt++] = i;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> k;
    cout << getNums(n) << endl;
    int x;
    while(k--){
        cin >> x;
        cout << ans[x-1] << " ";
    }
    return 0;
}
