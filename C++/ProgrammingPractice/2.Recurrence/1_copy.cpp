/*
* @file    :1_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/weixin_38894974/article/details/104359567
*          :
*          :
*/
#include<iostream>
#include<cstring>
#define NA 10000
using namespace std;
int visited[80][80];
int ei,ej,w,h,minl;
int dire[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};//左上右下 
char board[80][80];
void llk(int si,int sj,int l,int f){
	int i,x,y;
	if(l > minl)
		return;
	if(si == ei && sj == ej){
		if(l < minl)
			minl = l;
		return;
	}
	for(i = 0;i < 4; ++i){
		x = si + dire[i][0];
		y = sj + dire[i][1];
		if((x >= 0 && x <= w + 1 && y >= 0 && y <= h + 1) && ((board[x][y] == ' ' && visited[x][y] == 0) || (board[x][y] == 'X' && x == ei && y == ej))){
			visited[x][y] = 1;
			if(f == i)
				llk(x,y,l,i);
			else
				llk(x,y,l + 1,i);
			visited[x][y] = 0;
		}
	}
}
int main(){
	int i,j,bn,pn;
	bn = 0;
	while(1){
		scanf("%d%d",&h,&w);
		getchar();
		if(h == 0)
			break;
		bn++;
		printf("Board #%d:\n",bn);
		for(i = 0;i <= w + 1; ++i){
			for(j = 0;j <= h + 1; ++j){
				if((i == 0) || (i == w + 1) || (j == 0) || (j == h + 1))
					board[i][j] = ' ';
				else{
					scanf("%c",&board[i][j]);
				}
			}
			if(i >= 1 && i < w)
				getchar();
		}
		pn = 0;
		while(1){
			scanf("%d%d%d%d",&j,&i,&ej,&ei);
			memset(visited,0,sizeof(visited));
			if(i == 0){
				printf("\n");
				break;	
			}
			pn++;
			minl = NA;
			llk(i,j,0,-1);
			if(minl == NA)
				printf("Pair %d: impossible.\n",pn);
			else
				printf("Pair %d: %d segments.\n",pn,minl);
		}
	}
	return 0;
} 
