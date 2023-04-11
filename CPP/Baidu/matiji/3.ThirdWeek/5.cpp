/*
* @file    :5.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-18
* @brief   :MT2066相对马高
*          :差分、前缀和逆运算
*          :AC
*/
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int n, h, f;
    cin >> n >> h >> f;
    int he[n+1];
    he[0] = h;
    int sub[n+1];
    memset(sub,0,sizeof(sub));
    int a, b;
    while(f--){
        cin >> a >>b;
        if(a == b){
            continue;
        }
        if(a > b){
            swap(a,b);
        }
        sub[a + 1] -= 1;
        sub[b] += 1;
    }
    for(int i = 1; i<=n; i++){
        he[i] = he[i-1] + sub[i];
        cout << he[i] << endl;
    }
    return 0;
}
