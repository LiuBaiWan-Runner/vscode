https://blog.csdn.net/justidle/article/details/106060520

/*
OJ：luogu
题目：P1678 烦恼的高考志愿
地址：https://www.luogu.com.cn/problem/P1678
*/
#include <bits/stdc++.h>
 
const int MAXM = 1e5+2;
int a[MAXM];//学校分数
const int MAXN = 1e5+2;
int b[MAXM];//学生分数
 
int main() {
    int n, m;
    scanf("%d%d", &m, &n);
 
    int i;
    //读入学校分数
    for (i=0; i<m; i++) {
        scanf("%d", &a[i]);
    }
    //读入学生分数
    for (i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }
	
    std::sort(a, a+m);//排序
 
    //统计
    unsigned long long ans = 0;
    for (i=0; i<n; i++) {
        int lo = std::lower_bound(a, a+m, b[i]) - a;
        int hi = std::upper_bound(a, a+m, b[i]) - a;
        if (lo==hi) {
            //b[i]没有在a[i]中，找最小的
            if (0==lo) {
                ans += (a[lo]-b[i]);
            } else if (hi>=m) {
                ans += (b[i]-a[hi-1]);
            } else {
                ans += std::min(b[i]-a[lo-1], a[hi]-b[i]);
            }
        }        
    }
    printf("%llu\n", ans);
 
    return 0;
}