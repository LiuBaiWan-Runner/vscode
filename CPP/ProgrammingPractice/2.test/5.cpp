/*
* @file    :5.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :没通过
*          :
*          :
*/
#include <iostream>
#include <string>
using namespace std;
int ans = 0;
string s;


int main()
{
    int n;
    int p, q;
    int t;
    cin >> n;
    for(int i = 0; i<n; i++){
        s.clear();
        cin >> p >> q;
        cout << to_string(p) << '/' << to_string(q) << " = ";
        while(p % q != 0 && p % q != p / 10){
            t = p / q;
            s += to_string(t) + "+1/";
            s += '{';
            ans ++;
            p = (p % q)*10;
        }
        s += to_string(t);
        for(int j = 0; j<ans; j++){
            s += '}';
        }
        cout << s;
    }
    return 0;
}
