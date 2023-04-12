/*
 * @file    :11.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://www.cnblogs.com/jd1412/p/12569244.html
 *          :
 *          :
 */
#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<cstring>
using namespace std;
struct STU
{
    int xx;
    int yy;
};//定义结构体，分别表示点的横坐标和纵坐标

queue<STU> q;//定义在STU结构下的结构题
int go[5][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1}};//向四个方向走
int mapp[50][50],step[50][50];//mapp表示点的遍历情况，即vis；step表示走到该点的最小步数
int n,m,qx,qy,tx,ty;
char p[50][50];

int bfs(int x,int y)
{
     q.push((STU){x,y});//将第一组数据(起点）写入队列
     
     mapp[x][y]=1;
     step[x][y]=1;
     
     while(q.size()!=0)//当队列中的数据排空，即可停止
     {
         qx=q.front().xx;
         qy=q.front().yy;//取出队列中的第一个数
         q.pop();//没用了，扔掉
         
         if(qx==n&&qy==m)
         {
             return step[qx][qy];//搜到终点，返回答案
         }
         
         for(int i=1;i<=4;i++)
         {
             tx=qx+go[i][0];
             ty=qy+go[i][1];//临近的下一个点
             
             if(tx<1||n<tx||ty<1||m<ty)
             {
                 continue;//超出界限，跳过
            }
            
            if(mapp[tx][ty]==1||step[tx][ty]!=0)
            {
                continue;//若该点已经走过，明显地不可能会是最小，跳过
            }
            
            mapp[tx][ty]=1;//将符合条件的下一个点标记为已读
            step[tx][ty]=step[qx][qy]+1;//步数加一
            q.push((STU){tx,ty});//编入队列，从当前开始继续向下搜索
         }
     }
     return 0;
}

int main(void)
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>p[i][j];//输入
            
            if(p[i][j]=='#') mapp[i][j]=1;//当该点是障碍物的话，也是不能走的，与已读的点一样，标记
            else mapp[i][j]=0;
        }
    }
    cout<<bfs(1,1)<<endl;//从左上角开始搜索
    return 0;
}