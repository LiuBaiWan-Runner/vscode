/*
* @file    :10_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-16
* @brief   :UVA12032 The Monkey and the Oiled Bamboo【序列处理】
*          :https://www.codeleading.com/article/65205409686/
*          :
*/
/* UVA12032 The Monkey and the Oiled Bamboo */

#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 1;
int n, r[N];

bool judge(int k)
{
    for (int i = 0; i < n; i++) {
        int diff = r[i + 1] - r[i];
        if (diff == k) k--;
        else if (diff > k) return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
        r[0] = 0;

        int ans, left = 1, right = 1e7, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if (judge(mid)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }

        printf("Case %d: %d\n", k, ans);
    }

    return 0;
}
