/*
 * @file    :8_InfectiousChain.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-23
 * @brief   :InfectiousChain
 *          :建立接触图（使用动态数组存储邻接矩阵），存储时标记该人是否被接触传染过
 *          :由于不会重复接触并且传染源唯一，则没有被接触过的人就是传染源，根据标记找到他
 *          :然后以传染源为起点对图进行深搜，找到路径长度长于之前的就更新结果，
 *          :如果相等就不更新，由于邻接矩阵是按时间先后顺序存储，这样可以保持结果是最早的最长路径
 */

// 测试集不止一个传染源，详见8_InfectiousChain_detail.cpp

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4+10;
vector<int> G[N], ans, tmp; // 动态数组存储图的邻接矩阵，结果序列，临时结果序列
int n, m, t, mark[N]; // 总人数，当前人接触的人数，被接触的人，标记是否被接触
int start; // 传染源

void createG(); // 创建图
void findStart(); // 找到传染源
void dfs(int start); // 深搜以传染源开始的最长路径

int main()
{
    cin >> n;
    createG();
    findStart();
    dfs(start);
    cout << ans.size() + 1 << endl; //+1是加上开始结点
    cout << start;
    for(int i:ans){
        cout << ' ' << i;
    }
    return 0;
}

// 创建图
void createG(){
    for(int i = 0; i < n; i++){
        cin >> m;
        while(m--){
            cin >> t;
            G[i].push_back(t);
            mark[t] = 1; // 标记该人被接触传染过
        }
    }
}

// 找到传染源
void findStart(){
    for(int i = 0; i < n; i++){ // 遍历标记集
        if(!mark[i]){
            start = i;
            break;
        }
    }
}

// 深搜以传染源开始的最长路径
void dfs(int start){
    for(int i = 0; i < G[start].size(); i++){ // 递归进行深搜，更新临时结果集
        tmp.push_back(G[start][i]);
        dfs(G[start][i]);
        tmp.pop_back(); // 该路径所有结点都压入判断长度更新结果之后将栈弹空
    }
    if(tmp.size() > ans.size()){ // 该路径已经读取结束，与结果集比较长度，更新结果集
        ans = tmp;
    }
}