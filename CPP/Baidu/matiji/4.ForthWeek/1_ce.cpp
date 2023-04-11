/*
* @file    :1_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :MT2089逃课
*          :视频讲解例程
*          :
*/

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

struct Node{
    long long a, w;
}node[N];

long long n, sum, ans;

bool cmp(Node n1, Node n2){
    if(n1.a < n2.a){
        return true;
    }
    if(n1.a == n2.a && n1.w <= n2.w){
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> node[i].a >> node[i].w;
        sum += node[i].w;
    }
    sort(node, node+n, cmp);
    Node temp = node[0];
    for(int i = 0; i <= n; i++){
        if(node[i].a != temp.a){
            ans += temp.w;
        }
        temp = node[i];
    }
    cout << sum - ans << endl;
    return 0;
}
