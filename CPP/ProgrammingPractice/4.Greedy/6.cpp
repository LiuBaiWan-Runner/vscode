https://blog.csdn.net/weixin_52603147/article/details/127889665

#include<bits/stdc++.h>
using namespace std;
int k,zw,zs;
struct wu{
	double w,v;
	double zw;
} arr[10001];
bool cmp(wu w1,wu w2){
	return w1.zw>=w2.zw;
}
int main(){
	cin>>k;
	while(k--){
		cin>>zw>>zs;
		double maxx=0;
		for(int i=0;i<zs;i++){
			cin>>arr[i].w>>arr[i].v;
			//计算出没kg的价值
			arr[i].zw=arr[i].v/arr[i].w;
		}
		sort(arr,arr+zs,cmp);
		//开始装物品
		for(int i=0;i<zs;i++){
			//可以全部装下，全装
			if(zw>=arr[i].w){
				maxx+=arr[i].v;
				zw-=arr[i].w;
			}else{//装不下，尽可能装
				maxx+=arr[i].zw*zw;
				zw=0;
				break;
			}
		}
		printf("%.2lf\n",maxx);
	}
	
}
