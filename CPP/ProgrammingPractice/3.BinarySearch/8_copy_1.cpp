/*
* @file    :8_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :UVA10170 The Hotel with Infinite Rooms【(数学模拟)+二分查找】
*          :https://blog.csdn.net/tigerisland45/article/details/89409819
*          :
*/
/* UVA10170 The Hotel with Infinite Rooms */

#include <bits/stdc++.h>

typedef long long LL;

LL sum(LL s, LL n)
{
    return (n - s + 1) * (n + s) / 2;
}

LL bsearch(LL s, LL d)
{
    LL left = 1, right = 1e8, mid;
    while(left < right) {
        mid = left + (right - left) / 2;
        if(sum(s, mid) >= d)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

int main()
{
    LL s, d;
    while(~scanf("%lld%lld", &s, &d))
        printf("%lld\n", bsearch(s, d));

    return 0;
}
