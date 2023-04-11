/*
* @file    :4_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :poj 2456 Aggressive cows （最小值最大化二分问题）
*          :https://blog.csdn.net/qq_34374664/article/details/53366987
*          :
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 5;
const int maxn = 1e5 + 5;
int n, k, x[maxn];
int check(int d)   //这里一开始可能想不出来。。
{
    int last = 0;
    for(int i = 1; i < k; i++)  //这里写的很秒
    {
        int cur = last + 1;   //用两个变量“比”着判断。。再次知道用变量移动的妙处（上次潘学长写的优先队列那题也是）
        while(cur < n && x[cur] - x[last] < d)
            cur++;
        if(cur == n) return 0;
        last = cur;
    }
    return 1;
}
int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        sort(x, x+n);
        int l = 0, r = INF;
        while(r - l > 1)
        {
            int mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}