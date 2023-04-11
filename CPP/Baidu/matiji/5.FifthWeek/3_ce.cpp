/*
* @file    :3_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-30
* @brief   :MT2011名次并列
*          :先将成绩降序排序，小于等于k时取前边分数大于零的数量
*          :大于k时如果后边的分数和第k个一样，那么就增加一人。
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int n, k, a[N], ans;
bool cmp(int a, int b){
    return a > b;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i<=k; i++){
        if(a[i]>0){
            ans++;
        }
        else{
            cout << ans << endl;
            return 0;
        }
    }
    for(int i = k+1; i<=n; i++){
        if(a[i] == a[k]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
