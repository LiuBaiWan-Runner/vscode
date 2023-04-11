/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/weixin_45953673/article/details/105513675
 *          :
 *          :
 */
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K,N,R;
struct Road{
	int d,L,t;
};
vector<vector<Road> > G(110);
int minLen;
int totalLen;
int totalCost;
int visited[110];
void dfs(int s){
	if(s==N){
		minLen=min(totalLen,minLen);
		return;
	}
	for(int i=0;i<(int)G[s].size();++i){
		Road r=G[s][i];
		if(totalCost+r.t>K)
			continue;
		if(!visited[r.d]){
			if(minLen<=totalLen+r.L)
				continue;
			totalLen+=r.L;
			totalCost+=r.t;
			visited[r.d]=1;
			dfs(r.d);
			visited[r.d]=0;
			totalLen-=r.L;
			totalCost-=r.t;
		}
	}	
}
int main(){
	cin>>K>>N>>R;
	for(int i=0;i<R;++i){
		int s;		//边的起点 
		Road r;		//边的信息 
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d){
			G[s].push_back(r);
		}
	}
	memset(visited,0,sizeof(visited));
	totalLen=0;
	totalCost=0;
	minLen=1<<30;
	visited[1]=1;
	dfs(1);
	if(minLen<(1<<30)){
		cout<<minLen<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	return 0;
}
