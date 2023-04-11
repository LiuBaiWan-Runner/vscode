/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/freezhanacmore/article/details/8168265
 *          :
 *          :
 */
//Accepted	984K	79MS	C++	1128B	2012-11-10 00:44:26
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
 
const int maxn=100001;
 
bool vis[maxn];//标记数组
int step[maxn];//记录到了每一位置所走的步数
queue <int> q;//定义队列
 
int bfs(int n,int k)
{
    int head,next;
    q.push(n);   //开始FJ在n位置，n入队
    step[n]=0;
    vis[n]=true; //标记已访问
    while(!q.empty())  //当队列非空
    {
        head=q.front();  //取队首
        q.pop();         //弹出对首
        for(int i=0;i<3;i++)     //FJ的三种走法
        {
            if(i==0) next=head-1;
            else if(i==1) next=head+1;
            else next=head*2;
            if(next<0 || next>=maxn) continue; //排除出界情况
            if(!vis[next])  //如果next位置未被访问
            {
                q.push(next);    //入队
                step[next]=step[head]+1;  //步数+1
                vis[next]=true;  //标记已访问
            }
            if(next==k) return step[next];  //当遍历到结果，返回步数
        }
    }
    return 0;
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(step,0,sizeof(step));
        memset(vis,false,sizeof(vis));
        
        while(!q.empty()) q.pop(); //注意调用前要先清空
        if(n>=k) printf("%d\n",n-k);
        else printf("%d\n",bfs(n,k));
    }
    return 0;
}