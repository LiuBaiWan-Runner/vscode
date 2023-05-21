/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-18
 * @brief   :MT2143线段树
 *          :
 *          :
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
#define ll long long
struct Node
{
    ll l, r, val, lz;
} tree[4 * N];
ll a[N];

void build(ll p, ll l, ll r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
    {
        tree[p].val = a[l];
        return;
    }
    ll mid = l + ((r - l) >> 1);
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p].val = tree[p * 2].val + tree[p * 2 + 1].val;
}

void lazy(ll p, ll v)
{
    ll s = tree[p].l, t = tree[p].r;
    tree[p].val += (t - s + 1) * v, tree[p].lz += v;
}

void pushdown(ll p)
{
    lazy(2 * p, tree[p].lz);
    lazy(2 * p + 1, tree[p].lz);
    tree[p].lz = 0;
}

void update(ll l, ll r, ll c, ll p)
{
    ll s = tree[p].l, t = tree[p].r;
    if (l <= s && t <= r)
        return lazy(p, c);
    if (tree[p].lz && s != t)
        pushdown(p);
    ll mid = s + ((t - s) >> 1);
    if(l <= mid){
        update(l, r, c, p*2);
    }
    if (r > mid)
    {
        update(l, r, c, p * 2 + 1);
    }
    tree[p].val = tree[p * 2].val + tree[p * 2 + 1].val;
}

ll query(ll l, ll r, ll p)
{
    ll s = tree[p].l, t = tree[p].r;
    if (l <= s && t <= r)
        return tree[p].val;
    if (tree[p].lz)
        pushdown(p);
    ll mid = s + ((t - s) >> 1), sum = 0;
    if (l <= mid)
        sum = query(l, r, p * 2);
    if (r > mid)
        sum += query(l, r, p * 2 + 1);
    return sum;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--)
    {
        ll op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            update(x, y, k, 1);
        }
        else
        {
            cin >> x >> y;
            cout << query(x, y, 1) << endl;
        }
    }
    return 0;
}
