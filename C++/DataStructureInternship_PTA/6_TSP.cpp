/*
 * @file    :6_TSP.cpp
 * @author  :LiuBaiWan-Runner
 * @fstEdgersion :V1.0.0
 * @date    :2023-07-22
 * @brief   :TSP(TrafstEdgeling Salesman Problem)
 *          :求每个顶点的最大路径长度（拓扑排序）
 *          :采用邻接表方式储存村庄道路的有向无环图，然后进行拓扑排序的同时更新到达该点的最长路径长度
 *          :将所有入度为0的点入栈，取出每一个栈顶元素，更新它所有出边的尾结点的最大长度为当前节点长度+1和尾结点原始长度的最大值
 *          :然后更新最大长度，如果删除当前结点，他的邻居有入度为0的，入栈，继续取栈顶元素，直到栈空。
 */
#include <iostream>

using namespace std;

typedef struct EdgeNode EN;
typedef struct VillageNode VN;

const int N = 1e6+6;
int n, m, v1, v2;
int maxlen = 0, topStack[N], top = 0; // 初始化最大路径长度和拓扑排序所需要的栈

struct EdgeNode{ // 有向边结点
    int VNtail; // 边的权值为有向边的尾，标明边指向哪个结点，实现删除边后尾结点的入度减一
    EN* next = NULL; // 指针指向相同头结点的边，即邻接表存储
}* en;

struct VillageNode{ // 村庄结点
    int in = 0, len = 0; // in为结点的入度， len为结点当前的最大路径长度
    EN* fstEdge = NULL; // 指针指向一条出边，即邻接矩阵存储
// 通过这个指针和相同头节点的边的指针，实现删除入度为零的结点后，再删除该结点的所有出边。
}V[N];


void createG(); // 创建图
void topSort(); // 拓扑排序

int main()
{
    cin >> n >> m;
    createG();
    topSort();
    cout << maxlen + 1 << endl; // 最多经过的村庄数为最大顶点数即为最大路径长度加一
    return 0;
}

// 创建图，采用邻接表方式储存
void createG(){
    while(m--){
        cin >> v1 >> v2;
        en = new EN;
        en->VNtail = v2;
        V[v2].in++;
        en->next = V[v1].fstEdge;
        V[v1].fstEdge = en;
    }
}

// 拓扑排序
void topSort(){
    for(int i = 1; i < n; i++){
        if(!V[i].in){
            topStack[++top] = i; // 将所有入度为0的点入栈
        }
    }
    while(top){ // 循环直到栈空
		int t = topStack[top--];
		for(EN *p=V[t].fstEdge; p; p=p->next){
			V[p->VNtail].len = max(V[t].len+1, V[p->VNtail].len);
			maxlen = max(V[p->VNtail].len, maxlen);

            // 如果把p当前所指的边的尾结点入度减一，即删除这条边，则节点的入度为0，将其压入栈
			if(!(--V[p->VNtail].in)){
                topStack[++top] = p->VNtail;
			}
		}
	}
}


//本题的逻辑结构：图/栈
//本题的存储结构：链式
//解题思路和算法：采用邻接表方式储存村庄道路的有向无环图，然后进行拓扑排序的同时更新到达该点的最长路径长度
//               将所有入度为0的点入栈，取出每一个栈顶元素，更新它所有出边的尾结点的最大长度为当前节点长度+1和尾结点原始长度的最大值
//               然后更新最大长度，如果删除当前结点，他的邻居有入度为0的，入栈，继续取栈顶元素，直到栈空。
//效率：  时间复杂度：O(n^2)
//        空间复杂度：O(n)
/*测试数据：
输入：
4 3
1 4
2 4
4 3

-------------------------
输出：
3

*/