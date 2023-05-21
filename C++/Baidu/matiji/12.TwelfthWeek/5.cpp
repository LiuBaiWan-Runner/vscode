/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-18
 * @brief   :MT2141快排变形
 *          :
 *          :
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
int a[N], b[N], c[N], n;
long long ans;

int lowbit(int x){
    return x & -x;
}
void add(int i, int x){
    for(; i <= n; i += lowbit(i))
        c[i] += x;
}

int sum(int i){
    int ans = 0;
    for(; i > 0; i -= lowbit(i)){
        ans += c[i];
    }
    return ans;
}

bool cmp(const  int x, const int y){
    if(b[x] == b[y])
        return x > y;
    return b[x] > b[y];
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        a[i] = i;
    }
    sort(a+ 1, a+n+1, cmp);
    for(int i = 1; i <= n; i++){
        add(a[i], 1);
        ans += sum(a[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
