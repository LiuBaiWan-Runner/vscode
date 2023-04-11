/*
* @file    :9_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :UVA-10474（implements）
*          :https://blog.csdn.net/timelessx_x/article/details/116808752
*          :
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,q;
	int cnt=1;
	while(scanf("%d %d",&n,&q)==2&&n&&q){
		int a[n+1];
		printf("CASE# %d:\n",cnt);
		cnt++;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int num;
		
		for(int i=0;i<q;i++){
			cin>>num;
			int f=0;
			for(int j=0;j<n;j++){
				if(num==a[j]){
					f=1;
					printf("%d found at %d\n",num,j+1);
					break;
				}
			}
			if(!f)printf("%d not found\n",num);	
		}
	}
	return 0;
} 
