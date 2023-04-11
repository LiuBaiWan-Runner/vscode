https://blog.csdn.net/weixin_42105789/article/details/84546555

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
 
const int N=25;
int n,h;
int f[N],d[N],t[N];//f第一个五分钟钓的鱼量，d为每个五分钟减少的鱼量，t为i到i+1五分钟的个数 
int ans;
int each[N];//记录最终每条湖用的时间
int tans,teach[N];//最优钓鱼量和各湖钓鱼时间 
int th,tf[N];//有效钓鱼时间和每条湖前五分钟的钓鱼量 
 
int main()
{
	int i,j;
	while(cin>>n&&n>0){//当湖的数量为0的时候结束 
		cin>>h;//输入时间 
		for(i=0;i<n;i++){
			cin>>f[i];//第一次的鱼量 
		} 
		for(i=0;i<n;i++){
			cin>>d[i];//每五分钟减少的鱼量 
		}
		for(i=0;i<n-1;i++){
			cin>>t[i];//每个湖间距离需要的时间片 
		}
		h*=12;//一小时12个时间片
		ans=-1;
		for(i=0;i<n;i++){//表示再第i条湖停下来 
			//初始化每一次贪心
			th=h;//有效时间先初始化为总时间 
			for(j=0;j<n;j++){
				tf[j]=f[j];//每条湖初始的钓鱼量初始为第一次五分钟的钓鱼量 
				teach[j]=0;//每个湖的钓鱼时间初始化为0 
			} 
			tans=0;//最大钓鱼数初始化为0 
			
			//对每五分钟贪心选择钓鱼量最大的湖钓鱼 
			while(th>0){//当有效时间大于0 
				int ind=0,max=tf[0];//令第一条湖的鱼量为最大值 ，ind标记湖是第几条湖 
				for(j=0;j<=i;j++){
					if(tf[j]>max){//不考虑顺序先找第一次鱼量最大的湖 
						max=tf[j];
						ind=j;
					}
				}
				if(max==0){//最大钓鱼量为0时，将剩余的钓鱼时间加到第一个湖上的钓鱼时间 
					teach[0]+=th*5;//例如样例一 
					break;
				}
				else{
					teach[ind]+=5;//最大湖的钓鱼时间，每钓一次加一次五 
					tans+=tf[ind];//加上最大鱼量的湖的该次的鱼数 
					if(tf[ind]>=d[ind])//如果鱼量不少于减少的鱼数 ，则减 
					{
						tf[ind]-=d[ind];
					}
					else{
						tf[ind]=0;//小于减少数则赋值为0 
					}
				} 
				th--;//有效时间减少一个时间片(一个时间片五分钟) 
			}
			if(i!=n-1){//i的话是表示在第i条湖停下来 
				h-=t[i];//减去到下一条湖的时间片 
			}
			if(tans>ans){//如果值大于前面的值，就把值赋给ans 
				ans=tans;
				for(j=0;j<n;j++){
					each[j]=teach[j];//记录最终每条湖用的时间 
				}
			}
		} 
		cout<<each[0]; 
		for(i=1;i<n;i++){
			cout<<", "<<each[i];
		}
		cout<<endl;
		cout<<"Number of fish expected: "<<ans<<endl;
		cout<<endl;
	}
	return 0;
} 