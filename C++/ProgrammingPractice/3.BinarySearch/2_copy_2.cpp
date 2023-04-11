/*
* @file    :2_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :POJ 2503 Babelfish（map）
*          :https://www.cnblogs.com/lipeiyi520/p/11146526.html
*          :
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<map>

using namespace std;

map<string,string> a;
string l,l1,l2;
char p,lk;

int main() {
    while(true) {
        lk = getchar();
        if(lk == '\n') break;
        l = lk;
        while(true) {
            p = getchar();
            if(p == ' ') break;
            l += p;
        }
        lk = getchar();
        l1 = lk;
        while(true) {
            p = getchar();
            if(p == '\n') break;
            l1 += p;
        }
        a[l1] = l;
    }
    while(cin >> l2) {
        if(a.count(l2))
            cout << a[l2] << endl;
        else cout << "eh" << endl;
    }
    return 0;
}