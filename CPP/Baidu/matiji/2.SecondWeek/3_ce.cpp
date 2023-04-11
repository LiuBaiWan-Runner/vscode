/*
* @file    :3_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-06
* @brief   :MT2068高数考试
*          :视频讲解例程
*          :
*/
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int n, p;
    cin >> n >> p;
    int a[n+10], sub[n+10];
    memset(a,0,sizeof(a));
    memset(sub,0,sizeof(sub));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sub[i] = a[i] - a[i-1];
    }
    int x, y, z;
    for(int i = 1; i<=p; i++){
        cin >> x >> y >> z;
        sub[x] += z;
        sub[y+1] -= z;
    }
    int ans = 100;
    for(int i = 1; i<=n; i++){
        a[i] = a[i-1] +sub[i];
        ans = min(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}
