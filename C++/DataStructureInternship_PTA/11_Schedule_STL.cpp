/*
 * @file    :11_Schedule_STL.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-25
 * @brief   :Schedule
 *          :
 *          :
 */

#include <iostream>
#include <queue>
using namespace std;

#define ll long long
const int N = 4e6 + 10;

//结构体声明
struct Node {
    ll val;  //任务优先级
    string str;  //任务名
    //重载自定义优先级
    friend bool operator < (Node a, Node b) {
        if (a.val != b.val)
            return a.val > b.val;
        return a.str > b.str;
    }
} node;

priority_queue<Node> que;  //STL定义优先队列
int n,m;

void BuildMinHeap();
void PrintName();

int main(){
    cin >> n >> m;
    BuildMinHeap();
    PrintName();
    return 0;
}

void PrintName(){
    for(int i=0; i<m; i++){
        cout << que.top().str << endl;
        Node tmp = que.top();
        que.pop();
        tmp.val = tmp.val * 2;
        que.push(tmp);
    }
}

void BuildMinHeap(){
    if (n > N){
        return;
    }
    for(int i=0; i<n; i++){
        cin>>node.val>>node.str;
        que.push(node);
    }
}