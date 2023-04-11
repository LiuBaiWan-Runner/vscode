/*
* @file    :5_ce.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-29
* @brief   :MT2112逆序对（归并排序）
*          :视频讲解例程
*          :
*/
#include <iostream>

using namespace std;
int n, m, a[1510], q[1510], ans;

void merge_sort(int l, int r, int a[]){
    if(l >= r){
        return;
    }
    int mid = l+r >> 1;
    merge_sort(l, mid, a);
    merge_sort(mid+1, r, a);

    int i = l, j = mid+1, t = 0;
    while(i <= mid && j <= r){
        if(a[i] > a[j]){
            q[t++] = a[j++];
            ans +=mid-i+1;
        }
        else{
            q[t++] = a[i++];
        }
    }
    while(i <= mid)
        q[t++] = a[i++];
        
    while(j <= r)
        q[t++] = a[j++];
    
    for(i = l, j = 0; i<=r; i++, j++)
        a[i] = q[j];
}

int main()
{
    cin >> n;
    for(int i = 1; i<= n; i++)
        cin >> a[i];
    cin >> m;
    merge_sort(1, n, a);
    int l, r;
    while(m--){
        cin >> l >> r;
        ans = ans + (r-l+1)*(r-l)/2;
        cout << (ans%2 ? "odd" : "even") << endl;
    }
    return 0;
}
