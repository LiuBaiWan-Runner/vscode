/*
* @file    :5_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/Cosmic_Tree/article/details/105457821a
*          :
*          :
*/
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,t,mx,my,cx,cy,dx,dy,ans,maxx,flag;
bool vis[5010][5010];
struct ak
{
	int x;
	int y;
}a[5010];
bool cmp(ak xx,ak yy)
{
	if(xx.x==yy.x) return xx.y<yy.y;
	else return  xx.x<yy.x;
}
bool check(int x,int y)//检测是否在稻田内
{
	if(x>=1&&x<=n&&y>=1&&y<=m) return 1;
	else return 0;
}
int main( )
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i].x>>a[i].y;
		vis[a[i].x][a[i].y]=1;//标记此点被踩过
	}
	sort(a+1,a+t+1,cmp);//坐标排序，先按 x ,再按 y
	for(int i=1;i<t;i++)
	{
		mx=a[i].x,my=a[i].y;
		for(int j=i+1;j<=t;j++)
		{
			cx=a[j].x,cy=a[j].y;//枚举起始两点
			dx=cx-mx,dy=cy-my;
			if(mx+2*dx<1||mx+2*dx>n) break;
			//如果最起始点的 x 坐标加上两步后，超出稻田范围
			//直接结束此次枚举，枚举下一个最起始点
			//因为，排序按照 x 排序，它不行，他后面的也不行
			if(my+2*dy<1||my+2*dy>m) continue;
			//如果 y 超出范围，枚举下一个次起始点
			if(check(mx-dx,my-dy)) continue;
			//判断前一步是否在稻田内
			ans=1,flag=0;
			while(check(cx,cy))
			{
				if(vis[cx][cy]==0) 
				{
					flag=1;
					//如果落脚点没被踩过，标记，跳出
					break;
				} 
				cx+=dx,cy+=dy;
				ans++;
			}
			if(flag==0) maxx=max(maxx,ans);
			//最终结果取最大值
		}
	}
	cout<<maxx; 
	return 0;
}