/*
* @file    :4_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-29
* @brief   :MT2103摘果子
*          :视频讲解例程
*          :
*/
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10010;
struct Tree{
    int num, id;
    bool operator<(const Tree &x) const {
        return num < x.num;
    }
}tree[maxn];

int n, t, d[maxn], ti[maxn], ans;
priority_queue<Tree> q;

int main()
{
    cin >> n >> t;
    for(int i = 1; i<=n; i++){
        cin >> tree[i].num;
        tree[i].id = i;
    }
    for(int i = 1; i<=n; i++){
        cin >> d[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> ti[i];
    }
    for(int i = 1; i<=n; i++){
        t -= ti[i-1];
        int now = 0;
        while(!q.empty())
            q.pop();
        for(int j = 1; j<=i; j++){
            q.push(tree[j]);
        }
        for(int j = 1; j<=t; j++){
            Tree s;
            s = q.top();
            if(s.num >0){
                now += s.num;
            }
            s.num -= d[s.id];
            q.pop();
            q.push(s);
        }
        ans = max(ans, now);
    }
    cout << ans <<endl;
    return 0;
}
