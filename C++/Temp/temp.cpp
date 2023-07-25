/*
 * @file    :11_Schedule.cpp
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
    if(n1.name != n2.name){
        return n1.name < n2.name;
    }
}

int n,m;

void BuildMinHeap(int n);
void PrintValue();

int main(){
    cin >> n >> m;
    BuildMinHeap(n);
    PrintValue();
    for(int i = 0; i < m; i++){
        cout << node[1].name << endl;
        node[1].v = 2 * node[1].v;
        sort(node + 1, node + n + 1, cmp);
    }
    return 0;
}



void PrintValue()
{
    int i;
    printf("最小堆中的元素依次为：\n");
    for (i = 1; i <= n; i++)
        // printf("%d ", H->p[i]);
        cout << node[i].v << ' ' << node[i].name << endl;
    // printf("\n");
}

void BuildMinHeap(int n)
{
    int thisvalue;
    string thisname;

    if (n > N)
    {
        printf("要创建的元素个数超过堆的最大容量，创建失败");
        return;
    }
    node[0].v = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> thisvalue >> thisname;
        node[i].v = thisvalue;
        node[i].name = thisname;
        sort(node + 1, node + i + 1, cmp);
    }
}
