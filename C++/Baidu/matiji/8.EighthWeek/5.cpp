/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :MT2118合并货物
 *          :
 *          :
 */
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e4 + 7;

int n, tmp, tmp2, ans, a[N];
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    cin >> n;
    while(n--){
        cin >> tmp;
        q.push(tmp);
    }
    while(q.size() != 1){
        tmp = q.top();
        q.pop();
        tmp2 = tmp + q.top();
        q.pop();
        ans += tmp2;
        q.push(tmp2);
    }
    cout << ans << endl;
    return 0;
}
