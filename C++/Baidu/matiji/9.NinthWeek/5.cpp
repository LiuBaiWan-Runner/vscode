/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-26
 * @brief   :MT2127权值计算
 *          :
 *          :
 */
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], n, ans;
map<int, int> mp;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto tmp : mp){
        if(tmp.second >= tmp.first){
            ans = max(ans, tmp.first);
        }
    }
    cout << ans << endl;
    return 0;
}
