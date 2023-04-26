/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-26
 * @brief   :MT2129给单词分类
 *          :
 *          :
 */
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, ans;
string s;
map<string,int>mp;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        sort(s.begin(), s.end());
        if(!mp[s]){
            ans++;
            mp[s] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}