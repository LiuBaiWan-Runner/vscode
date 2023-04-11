/*
* @file    :10_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-16
* @brief   :UVA12032 The Monkey and the Oiled Bamboo【序列处理】
*          :https://blog.csdn.net/tigerisland45/article/details/115220066
*          :
*/
/* UVA12032 The Monkey and the Oiled Bamboo */

#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 1;
int n, r[N], d[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
        r[0] = 0;

        int ans = -1;
        for (int i = 0; i < n; i++)
            d[i] = r[i + 1] - r[i];
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == ans) ans++;
            ans = max(ans, d[i]);
        }

        printf("Case %d: %d\n", k, ans);
    }

    return 0;
}
