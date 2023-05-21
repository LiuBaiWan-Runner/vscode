/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-05-18
 * @brief   :MT2134泡泡
 *          :
 *          :
 */
#include <iostream>

using namespace std;
const int N = 1e5+7;
struct Node{
    int l, r;
    bool flag;
}bubb[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        bubb[i].l = bubb[i].r = i;
    }
    while (m--){
        int x, y;
        cin >> x >> y;
        int t1 = bubb[x].r, t2 = bubb[y].l;
        bubb[x].r = y, bubb[y].l = x;
        bubb[t1].l = t2, bubb[t2].r = t1;
    }
    for(int i = 1; i <=n; i++){
        if(!bubb[i].flag){
            int temp = i;
            while (!bubb[temp].flag){
                cout << temp << " ";
                bubb[temp].flag = true;
                temp = bubb[temp].r;
            }
            cout << endl;
        }
    }
    return 0;
}
