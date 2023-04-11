/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :MT2079第k小距离
*          :
*          :AC
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6+10;
int n, k, l, r, mid, ans, a[N];

bool check(int num){
    int cnt = 0;
    for(int r2 = 0; r2 < n; r2++){
        int l2 = 0;
        while(a[r2] - a[l2] > num && r2 > l2)
        l2++;
        cnt += r2 - l2;
    }
    return cnt >= k;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    r = a[n-1] - a[0];
    while(l <= r){
        mid = l + (r-l)/2;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
