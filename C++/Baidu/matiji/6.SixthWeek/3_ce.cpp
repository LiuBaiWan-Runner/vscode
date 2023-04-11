/*
* @file    :3_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-05
* @brief   :MT2075礼物（二分）
*          :视频讲解例程
*          :
*/
#include <iostream>

using namespace std;
int cnt1, cnt2, x, y;

bool check(int num){
    if(num-num/(x*y) < cnt1+cnt2){
        return false;
    }
    if(num-num/x < cnt1){
        return false;
    }
    if(num-num/y < cnt2){
        return false;
    }
    return true;
}

int main()
{
    cin >> cnt1 >> cnt2 >> x >> y;
    int left = 1, right = 2e9, mid;
    int ans;
    while(left <= right){
        mid = (left+right)/2;
        if(check(mid)){
            right = mid-1, ans = mid;
        }
        else{
            left = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}
