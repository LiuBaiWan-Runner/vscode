/*
 * @file    :11_Schedule_sort.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-24
 * @brief   :Schedule
 *          :
 *          :
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
