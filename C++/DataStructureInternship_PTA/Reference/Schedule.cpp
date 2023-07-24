#include<bits/stdc++.h>
using namespace std;

//结构体声明
struct Node {
    long long int val;  //任务优先级
    char str[8];  //任务名
    //重载自定义优先级
    friend bool operator < (Node a, Node b) {
        if (a.val != b.val)
            return a.val > b.val;
        return strcmp(a.str, b.str) > 0;
    }
};

int main()
{
    priority_queue<Node> que;  //STL定义优先队列
    int n,m;
    Node node;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>node.val>>node.str;
        que.push(node);
    }
    for(int i=0; i<m; i++){
        if(!que.empty()){
            cout<<que.top().str<<endl;
            Node node2 = que.top();
            node2.val = que.top().val*2;
            que.push(node2);
            que.pop();
        }
    }
    return 0;
}
