/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-10
 * @brief   :Mt2133一元多项式的加法
 *          :
 *          :
 */
#include <iostream>

using namespace std;
#define ll long long
const int N = 2e6 + 10;

struct Node{
    ll nex, coef, expn;
} node[N];
int n, m, head, tail, pos;
ll coefA[N], expnA[N], coefB[N], expnB[N];

void insert(int curr, ll val1, ll val2){
    node[++pos].coef = val1;
    node[pos].expn = val2;
    node[pos].nex = node[curr].nex;
    node[curr].nex = pos;
    if(!node[pos].nex)
        tail = pos;
}

int main()
{
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        // cin >> coefA[i] >> expnA[i];
        scanf("%lld%lld", &coefA[i], &expnA[i]);
    for(int i = 1; i <= m; i++)
        // cin >> coefB[i] >> expnB[i];
        scanf("%lld%lld", &coefB[i], &expnB[i]);
    
    int l = 1, r = 1;
    while(l <= n && r <= m){
        if(expnA[l] == expnB[r]){
            insert(tail, coefA[l] + coefB[r], expnA[l]);
            l++, r++;
        }
        else{
            if(expnA[l] < expnB[r]){
                insert(tail, coefA[l], expnA[l]);
                l++;
            }
            else{
                insert(tail, coefB[r], expnB[r]);
                r++;
            }
        }
    }
    while(l <= n){
        insert(tail, coefA[l], expnA[l]);
        l++;
    }
    while(r <= m){
        insert(tail, coefB[r], expnB[r]);
        r++;
    }
    for(int i = node[head].nex; i != 0; i = node[i].nex){
        if(node[i].coef != 0)
            // cout << node[i].coef << ' ' << node[i].expn << endl;
            printf("%lld %lld\n", node[i].coef, node[i].expn);
    }
    return 0;
}
