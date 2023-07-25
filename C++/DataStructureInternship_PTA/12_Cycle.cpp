/*
 * @file    :12_Cycle.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-25
 * @brief   :Cycle
 *          :输入两个字符串s1和s2，令字符串s = s1 + s1
 *          :若s2是s的子串（s.find(s2)返回s2在s中的位置），则s1可以通过若干次循环移位得到s2
 *          :否则（s.find(s2)返回-1）则不能
 */
#include <iostream>
using namespace std;

int n;
string s1, s2, s;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s1 >> s2;
        s = s1 + s1;
        if (s.find(s2) == -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}
