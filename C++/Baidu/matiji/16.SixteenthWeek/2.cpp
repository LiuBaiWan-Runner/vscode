/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-14
 * @brief   :MT2167拼写检测
 *          :
 *          :
 */
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
vector<int> ans;
string dict[N], s;
int n;
int diff(int id){
    if(s.length() == dict[id].length()){
        if(s == dict[id])
            return 1;
        else
            return -1;
    }
    if(s.length() == dict[id].length() + 1){
        int i = 0;
        while(s[i] == dict[id][i] && i < dict[id].length())
            i++;
        i++;
        while(s[i] == dict[id][i - 1] && i < s.length())
            i++;
        return (i == s.length() ? 2 : -1);
    }
    return -1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dict[i];
    }
    cin >> s;
    for(int i = 1; i <= n; i++){
        int temp = diff(i);
        if(temp == 1){
            cout << 0;
            return 0;
        }
        if(temp == 2)
            ans.push_back(i);
    }
    if(ans.empty()){
        cout << -1;
    }
    else{
        cout << ans.size() << endl;
        for(auto i : ans){
            cout << dict[i] << endl;
        }
    }
    return 0;
}
