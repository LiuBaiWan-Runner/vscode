/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-12
 * @brief   :MT2121大约（优先队列，双指针）
 *          :
 *          :
 */
#include <iostream>
#include <queue>
using namespace std;

priority_queue <int> max2, maxDel;
priority_queue <int, vector<int>, std::greater<int>> min2, minDel;

int main()
{
    int n, ans = 0;
    cin >> n;
    int a[n+10];
    for(int i = 1, j = 1; i <= n; i++){
        cin >> a[i];
        max2.push(a[i]);
        min2.push(a[i]);
        while(max2.top() - min2.top() > 1){
            maxDel.push(a[j]);
            minDel.push(a[j]);
            j++;
            while(maxDel.size() && max2.top() == maxDel.top()){
                max2.pop();
                maxDel.pop();
            }
                
            while(minDel.size() && min2.top() == minDel.top()){
                min2.pop();
                minDel.pop();
            }
        }
        ans = max(ans, i-j+1);
    }
    cout << ans << endl;
    return 0;
}
