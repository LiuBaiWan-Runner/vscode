/*
 * @file    :6.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/justidle/article/details/104662118
 *          :
 *          :
 */
#include <cstdio>
#include <queue>
 
//位置定义
struct POS {
	int x, y;//坐标
	int cost;//本节点到起点的距离
};
 
const int MAXN = 202;
struct MAZE {
	int row, col;//迷宫大小
	char data[MAXN][MAXN];//迷宫数据描述
	bool visit[MAXN][MAXN];//是否已经访问过节点
	int x1, y1;//起点坐标
	int x2, y2;//终点坐标
};
 
int bfs(MAZE &maze);
 
int main() {
	MAZE maze = {};//迷宫定义并将所有初始化为零

	int n;
    scanf("%d", &n);
    while(n--){

	//读入迷宫长宽 
	scanf("%d %d", &maze.row, &maze.col);
	
	//读入迷宫数据
	int i,j;
	for (i=0; i<maze.row; i++) {
		for (j=0; j<maze.col; j++) {
			scanf(" %c", &maze.data[i][j]);
			if (maze.data[i][j]=='a') {
				//终点
				maze.x2 = i;
				maze.y2 = j; 
			} else if (maze.data[i][j]=='r') {
				//起点
				maze.x1 = i;
				maze.y1 = j; 
			}
		}
	} 
	
	int ans = bfs(maze);
	
	if (ans>0) {
		printf("%d\n", ans);
	} else {
		printf("Impossible\n");
	}
    }
	return 0;
}
 
int bfs(MAZE &maze) {
	std::queue<POS> q;//下一个节点队列
	const POS move[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};//骑士的移动方法
	POS cur;//当前位置
        POS next;//下一个位置
	
	//加入起点
	cur.x = maze.x1;
	cur.y = maze.y1;
	cur.cost = 0;
	maze.visit[cur.x][cur.y] = true;//设置本节点已经访问
	q.push(cur); 
	
	//开始遍历
	while (!q.empty()) {
                //弹出队首节点
		cur = q.front();
		q.pop();
		
		if (maze.data[cur.x][cur.y]=='x') {
			//由于有干掉守卫，所以我们我们先加入的不一定是最小的
			maze.data[cur.x][cur.y]='@';
			cur.cost++;
			q.push(cur);
		} else {
			for (int i=0; i<4; i++) {
				next.x = cur.x + move[i].x;
				next.y = cur.y + move[i].y;
				
				//判断是不是终点
				if (next.x==maze.x2 && next.y==maze.y2) {
					return cur.cost + 1;
				} 
				
				//判断通过性
				if (next.x>=0&&next.x<maze.row&&next.y>=0&&next.y<maze.col&&maze.visit[next.x][next.y]==false&&maze.data[next.x][next.y]!='#') {
					next.cost = cur.cost + 1;
					maze.visit[next.x][next.y] = true;
					q.push(next);
				}
			}
		}
	}
	
	return -1; 
}