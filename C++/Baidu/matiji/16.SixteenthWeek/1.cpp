/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-14
 * @brief   :MT2168默契的配合
 *          :
 *          :
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n, cl, op;
string s, t;

int main()
{
    cin >> n >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(cl = 0; cl < min(s.length(), t.length()); cl++){
        if(s[cl] != t[cl])
            break;
    }
    op = s.length() + t.length() - 2 * cl;
    if(n >= op && (n - op) % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
