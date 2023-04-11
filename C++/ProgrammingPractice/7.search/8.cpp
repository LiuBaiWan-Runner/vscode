/*
 * @file    :8.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/qq_44643644/article/details/105939639
 *          :
 *          :
 */

#include<stdio.h>

int n,k;//棋盘尺寸，棋子数目
int ans;//摆放方案数
char map[9][10];//描述棋盘的内容
bool vis[9];//记录棋盘里已经被占用的列
//当前摆放棋盘第几行，当前还有几个棋子未摆放
void dfs(int now,int last)
{
    if(last==0){//没有剩余棋子，都摆放完了
        ans++;//找到一种摆放方案
        return;
    }
    if(now>n){//当前方案不合法，回退，重新搜索
        return;
    }
    //按列枚举
    for(int j=1;j<=n;j++)
    {//是空白区域或者已经被占用
        if(map[now][j]=='.'||vis[j]) continue;
        vis[j]=true;//标记
        dfs(now+1,last-1);//摆下一行，棋子数减1
        vis[j]=false;//回溯
    }
    //这一行没有摆棋子，到下一行去摆
    dfs(now+1,last);
    return;
}

int main()
{
    while(1)
    {
        scanf("%d%d",&n,&k);
        if(n==-1&&k==-1) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&map[i][1]);
        }
        ans=0;//答案清零
        for(int i=0;i<9;i++)
        {//标记数组也清零
            vis[i]=0;
        }
        dfs(1,k);//开始搜索
        printf("%d\n",ans);
    }
    return 0;
}
