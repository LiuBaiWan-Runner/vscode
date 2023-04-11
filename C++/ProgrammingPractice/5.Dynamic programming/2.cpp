/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :POJ2533 Longest Ordered Subsequence【最长上升子序列+DP】
*          :https://blog.csdn.net/tigerisland45/article/details/72847897
*          :
*/
/* POJ2533 Longest Ordered Subsequence */
 
#include <iostream>
 
using namespace std;
 
const int N = 1000;
int a[N], dp[N];
 
int lis(int n)
{
    int res = 0;
 
    for(int i=0; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    return res;
}
 
int main()
{
    int n;
    while(cin >> n) {
        for(int i=0; i<n; i++)
            cin >> a[i];
 
        cout << lis(n) << endl;
        break;
    }
 
    return 0;
}