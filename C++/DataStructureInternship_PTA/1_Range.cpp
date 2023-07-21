/*
 * @file    :1_Zuma.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :Range
 *          :线性结构
 *          :
 */
#include <iostream>

using namespace std;

const int N = 5e5+7;
int n, m, a, b, ans;
int s[N];

int search(int a, int b){   //查询是否在区间[a,b]内
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] >= a && s[i] <= b){
            ans++; //s[i]在[a,b]内，+1
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    while(m--){
        cin >> a >> b;
        cout << search(a, b) << endl;
    }
    return 0;
}
