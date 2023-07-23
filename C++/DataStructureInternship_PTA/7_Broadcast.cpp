/*
 * @file    :7_Broadcast.cpp
 * @author  :LiuBaiWan-Runner
 * @version :t1.0.0
 * @date    :2023-07-23
 * @brief   :Broadcast
 *          :BFS+队列
 *          :
 */
#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n, m, t1, t2;
int q[N], head = 0, tail = 0; // 初始化顺序队列

typedef struct EdgeNode EN;
typedef struct TownNode TN;

struct EdgeNode{ // 有向边结构体
    int TNtail; // 尾结点
    EN* next = NULL;
}* en;

struct TownNode{
    int state = 0; // 当前结点的状态值
    EN* fstEdge = NULL;
}towns[N];

void createG(); // 创建图
bool dfs(int a); // 广度优先遍历

int main(){
    cin >> n >> m;
    createG();
    for(int i = 1; i < n; i++){ // 从第一个结点开始广度优先遍历图
        if(!towns[i].state){ // 当前结点的状态为0，即还没有遍历，同时避免遗漏孤立结点和不连通结点
            if(!dfs(i)){
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << "1" << endl; 
    return 0;
}

// 创建图，采用邻接表方式储存
void createG(){
    while(m--){
        cin >> t1 >> t2;
        en = new EN;
        en->TNtail = t2;
        en->next = towns[t1].fstEdge; // 插入边结点
        towns[t1].fstEdge = en;
    }
}


// 广度优先遍历当前结点
bool dfs(int a){
    q[tail++] = a; // 把当前结点入队
    towns[a].state = 1; // 修改当前结点的状态为1
    while(head < tail){ // 队列不空
        TN t = towns[q[head]]; // t为当前队列头节点
        EN* e = t.fstEdge; // e为当前头节点t的出边
        while(e != NULL){ // 遍历所有出边
            if(!towns[e->TNtail].state){ // 如果出边的尾结点状态为0
                towns[e->TNtail].state = -t.state; // 那么更新e的尾结点的状态为当前头节点的状态负值
                q[tail++] = e->TNtail; // 把e的尾结点入队
            }
            else if(towns[e->TNtail].state == t.state){ // 如果存在两个相邻结点的状态相同则无法实现，输出-1
                return false;
            }
            e = e->next; // 判断更新下一条边尾结点的状态
        }
        head++; // 当前结点所有边遍历完判断更新下一个相邻结点状态
    }
    return true; // 当前连通分量的所有相邻结点的状态都不相同，满足条件，继续遍历下一个连通分量
}