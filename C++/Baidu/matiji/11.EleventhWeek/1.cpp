/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-10
 * @brief   :MT2140供水管线
 *          :
 *          :
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e2+10;

struct Node{
    int i, j, c;
    bool operator<(const Node &t) const{
        return c < t.c;
    }
}p[N];

int fa[N], n, k, ans;
void init(){
    for(int i = 1; i < N; i++){
        fa[i] = i;
    }
}

int find(int x){
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void mer(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        fa[x] = y;
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> p[i].i >> p[i].j >> p[i].c;
    sort(p+1, p+1+k);
    for(int i = 1; i <= k; i++){
        if(find(p[i].i) != find(p[i].j)){
            ans += p[i].c;
            mer(p[i].i, p[i].j);
        }
    }
    cout << ans << endl;
    return 0;
}
