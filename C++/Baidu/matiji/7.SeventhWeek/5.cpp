/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-15
 * @brief   :MT2120第k小函数值
 *          :
 *          :
 */
#include <iostream>
#include <queue>
using namespace std;

struct NODE{
    int ans, a, b, c, x;
    bool operator>(const NODE &n) const {
        return ans > n.ans;
    }
};
priority_queue<NODE, vector<NODE>, greater<NODE>>q;
int n, k;
int fuc(int a, int b, int c, int x){
    return a*x*x + b*x + c;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        q.push({fuc(a, b, c, 1),
                    a, b, c, 1});
    }
    while(k--){
        NODE t = q.top();
        q.pop();
        q.push({fuc(t.a, t.b, t.c, t.x+1),
                    t.a, t.b, t.c, t.x+1});
        if(k == 0){
            cout << t.ans;
        }
    }
    return 0;
}
