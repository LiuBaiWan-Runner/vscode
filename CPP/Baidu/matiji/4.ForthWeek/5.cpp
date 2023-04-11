/*
* @file    :5.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-24
* @brief   :MT2069等差
*          :
*          :
*/
#include <iostream>

using namespace std;
const int N = 5010;
int nums[N], sub[N], n, ans;

int main()
{
    int x;
    while(cin >> x){
        n++;
        nums[n] = x;
        sub[n] = nums[n] - nums[n-1];
    }
    for(int i = 2; i<n; i++){
        int temp = sub[i], index = i+1, t = 0;
        while(sub[index] == temp){
            t++;
            index++;
        }
        ans +=t;
    }
    cout << ans;
    return 0;
}
