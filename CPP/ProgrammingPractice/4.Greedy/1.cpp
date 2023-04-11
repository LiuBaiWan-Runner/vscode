https://blog.csdn.net/weixin_44572229/article/details/119277234

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct gift{
	int value;
	int weight;
	double density;
}gf[101];
bool cmp(gift f1,gift f2){  //按照单重价值从大到小排序
	return f1.density > f2.density;
}
int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>gf[i].value>>gf[i].weight;
		gf[i].density=1.0*gf[i].value/gf[i].weight;
	}
	sort(gf,gf+n,cmp);
	double totw=0,totv =0; //注意到w为int型，可拆分为double型
	//所以新建一个double型保存背包剩余重量
		for(int i=0;i<n;i++){
			if(totw + gf[i].weight<=w){
				totw+=gf[i].weight;
				totv+=gf[i].value;
			}else{
				totv+=gf[i].density *(w-totw);
				totw = w;
				break;
			}
		}
	printf("%.1lf",totv);
	return 0;
}