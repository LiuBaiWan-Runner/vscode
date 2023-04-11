/*
 * @file    :2_ce.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-03-30
 * @brief   :MT2104能量供应
 *          :将连接区间按右端点升序排序，同时满足条件的应选择后边的
 *          :有尽可能大的重复区域，这样可以减少建塔数量。
 *          :AC
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Tower
{
    int s, e, t;
} tower[N];
int n, b, ans;
bool build[N];
bool cmp(Tower a, Tower b)
{
    return a.e < b.e;
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> tower[i].s >> tower[i].e >> tower[i].t;
    }
    sort(tower + 1, tower + 1 + b, cmp);

    for (int i = 1; i <= b; i++)
    {
        int count = 0;
        for (int j = tower[i].s; j <= tower[i].e; j++)
        {
            if (build[j])
            {
                count++;
            }
        }
        if (count >= tower[i].t)
            continue;
        for (int j = tower[i].e; j >= tower[i].s; j--)
        {
            if (!build[j])
            {
                build[j] = true;
                count++;
                ans++;
                if (count == tower[i].t)
                    break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}