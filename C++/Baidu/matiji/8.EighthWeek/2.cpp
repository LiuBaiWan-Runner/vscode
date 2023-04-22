/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-21
 * @brief   :MT2119合并石子
 *          :
 *          :
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
ll w, n, ans;

struct Node
{
    ll a, b;
    bool operator>(const Node &t) const
    {
        return a > t.a;
    }
} tmp, tmp2;
priority_queue<Node, vector<Node>, greater<Node>> q;

int main()
{
    cin >> w;
    while (w--)
    {
        ans = 0;
        cin >> n;
        while (!q.empty())
        {
            q.pop();
        }
        q.push({1, n});
        while (!(q.size() == 1 && q.top().b == 1))
        {
            tmp = q.top(), q.pop();
            if (tmp.b == 1)
            {
                tmp2 = q.top(), q.pop();
                ans += tmp2.a - tmp.a;
                q.push({tmp.a + tmp2.a, 1});
                if (tmp2.b != 1)
                    q.push({tmp2.a, tmp2.b - 1});
            }
            else
            {
                if (tmp.b % 2)
                {
                    q.push({tmp.a * 2, tmp.b / 2});
                    q.push({tmp.a, 1});
                }
                else
                {
                    q.push({tmp.a * 2, tmp.b / 2});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
