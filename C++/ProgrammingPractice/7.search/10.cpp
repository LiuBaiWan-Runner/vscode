/*
 * @file    :10.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/qq_41890797/article/details/81224489
 *          :
 *          :
 */
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
int minn,dir[5][2]={0,0,0,1,1,0,0,-1,-1,0};
char str[5][5];
bool check()   //检查整个矩阵是否只有一种颜色
{
    char c=str[0][0];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(str[i][j]!=c)
        return 0;
    return 1;
}
void swap1(int x,int y)  //翻转这个点，及其四周的点
{
    for(int i=0;i<5;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||xx>=4||yy<0||yy>=4)
            continue;
        if(str[xx][yy]=='w')
            str[xx][yy]='b';
        else if(str[xx][yy]=='b')
            str[xx][yy]='w';
    }
}
void dfs(int x,int y,int step)
{
    if(step>16)   //翻了16次  已经不能再求出了
        return;
    if(check())   //检查是否达到目标状态
    {
        if(step<minn)   //维护最小值
            minn=step;
        return;
    }
    if(y>=4)   //因为是按行走的，当走到行末时，就需要跳到下一行的第一个
    {
        x++;
        y=0;
    }
    if(x>=4)  //矩阵找完了
        return;
    for(int i=0;i<2;i++)  //每个点的两种状态
    {
        if(i==0)   //翻
        {
            swap1(x,y);  
            dfs(x,y+1,step+1);
            swap1(x,y);   //把翻过的点恢复
        }
        else    //不翻
            dfs(x,y+1,step);
    }
}
int main()
{
    minn=inf;
    for(int i=0;i<4;i++)
        scanf("%s",str[i]);
    dfs(0,0,0);    //从第一个点开始枚举
    if(minn<=16)    //有最小值
        printf("%d\n",minn);
    else
        printf("Impossible\n");
}