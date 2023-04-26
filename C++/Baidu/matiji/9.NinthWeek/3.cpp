/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-26
 * @brief   :MT2128黑客小马哥
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s1, s2;
int str1[30], str2[30];

int main()
{
    while(cin >> s1 >> s2){
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        if(s1.length() != s2.length()){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < s1.length(); i++){
            str1[s1[i] - 'A']++;
            str2[s2[i] - 'A']++;
        }
        sort(str1, str1 + 26);
        sort(str2, str2 + 26);
        bool flag = true;
        for(int i = 0; i<26; i++){
            if(str1[i] != str2[i]){
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
    }
    return 0;
}
