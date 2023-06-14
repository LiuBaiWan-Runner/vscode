/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-14
 * @brief   :MT2171 s的排列
 *          :
 *          :
 */
#include <iostream>
#include <vector>
using namespace std;
string s1, s2;

int main()
{
    cin >> s1;
    cin >> s2;
    int l1 = s1.length(), l2 = s2.length();
    if(l1 > l2){
        cout << "false";
        return 0;
    }
    vector<int> a1(26), a2(26);
    for(int i = 0; i < l1; i++){
        a1[s1[i] - 'a']++;
        a2[s2[i] - 'a']++;
    }
    if(a1 == a2){
        cout << "true";
        return 0;
    }
    for(int i =l1; i < l2; i++){
        a2[s2[i] - 'a']++;
        a2[s2[i - l1] - 'a']--;
        if(a1 == a2){
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}
