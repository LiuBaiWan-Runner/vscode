/*
* @file    :4.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-24
* @brief   :MT2078甜品配置
*          :视频讲解例程（优先队列+排序+二分）
*          :
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
struct Sweet{
    int a, b;
}sw[N];
int v, n, m, l, r, mid, result, sum_front[N], sum_behind[N];

bool cmp(Sweet s1, Sweet s2){
    return s1.a < s2.a;
}

bool check_odd(int i){
    if(sum_front[i-1] + sum_behind[i+1] + sw[i].b <= v){
        return true;
    }
    return false;
}

bool check_even(int i, int mid){
    if(sum_front[i-1] + sum_behind[mid] + sw[i].b <= v){
        return true;
    }
    return false;
}

int main()
{
    cin >> v >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> sw[i].a >> sw[i].b;
    }
    sort(sw+1, sw+n+1, cmp);

    priority_queue<int> q1, q2;
    for(int i = 1; i<=n; i++){
        q1.push(sw[i].b);
        sum_front[i] = sum_front[i-1] + sw[i].b;
        if(q1.size() > m/2-1 + m%2){
            sum_front[i] -= q1.top();
            q1.pop();
        }
    }
    for(int i = n; i>0; i--){
        q2.push(sw[i].b);
        sum_behind[i] = sum_behind[i+1] + sw[i].b;
        if(q2.size() > m/2){
            sum_behind[i] -= q2.top();
            q2.pop();
        }
    }

    if(m%2){
        for(int i = n-m/2; i>m/2; i--){
            if(check_odd(i)){
                cout << sw[i].a << endl;
                break;
            }
        }
    }
    else{
        for(int i = m/2; i<=n-m/2; i++){
            l = i+1;
            r = n-m/2+1;
            int temp = 0;
            while(l<=r){
                mid = l + (r-l)/2;
                if(check_even(i, mid)){
                    l = mid+1;
                    temp = mid;
                }
                else{
                    r = mid-1;
                }
                if(temp>i){
                    result = max(result, sw[i].a + sw[temp].a);
                }
            }
        }
        cout << result/2 << endl;
    }
    return 0;
}
