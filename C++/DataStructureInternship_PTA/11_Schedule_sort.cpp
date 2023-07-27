/*
 * @file    :11_Schedule_sort.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-24
 * @brief   :Schedule
 *          :任务节点使用结构体存储优先级和任务名称，借助STL中sort函数，并自定义cmp排序方式构建最小堆
 *          :执行m次：取出堆顶元素后，将优先度加倍重新加入堆中，并重新进行排序
 *          :cmp排序方式为：如果优先级不相同，就按照优先级从小到大排序，否则按照 任务名称ASCII排序
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 4e6 + 10;

struct Node{
    ll v;
    string name;
} node[N];

bool cmp(Node n1, Node n2){
    if(n1.v != n2.v){
        return n1.v < n2.v;
    }
    return n1.name < n2.name;
}

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
    for(int i = 0; i < m; i++){
        cout << node[1].name << endl;
        node[1].v = 2 * node[1].v;
        sort(node + 1, node + n + 1, cmp);
    }
}

void BuildMinHeap(){
    if (n > N){
        return;
    }
    node[0].v = -1;
    for (int i = 1; i <= n; i++){
        cin >> node[i].v >> node[i].name;
        sort(node + 1, node + i + 1, cmp);
    }
}


//本题的逻辑结构：二叉树
//本题的存储结构：顺序
//解题思路和算法：任务节点使用结构体存储优先级和任务名称，借助STL中sort函数，并自定义cmp排序方式构建最小堆
//               执行m次：取出堆顶元素后，将优先度加倍重新加入堆中，并重新进行排序
//               cmp排序方式为：如果优先级不相同，就按照优先级从小到大排序，否则按照任务名称ASCII排序
//效率：  时间复杂度：O(n^2log2n)
//        空间复杂度：O(n)
/*测试数据：
输入：
3 3
1 hello
2 world
10 test

-------------------------
输出：
hello
hello
world

*/