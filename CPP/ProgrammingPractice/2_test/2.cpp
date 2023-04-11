/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :https://www.cnblogs.com/gccbuaa/p/6872261.html
*          :
*          :
*/
#include <iostream>
#include <string.h>
using namespace std;
int change(char *a,int k){
	int len=strlen(a);
	int ans=0;
	for (int i=0;i<len;i++){
		ans = ans*k + a[i]-'0';
	}
	return ans;
}
bool isBig(char *a,int k){
	int len=strlen(a);
	for (int i=0;i<len;i++){
		if (a[i]-'0'>=k)
			return false;
	}
	return true;
}
int main(){
	char a[10],b[10],r[10];
	int t,i;
	cin>>t;
	while (t--){
		cin>>a>>b>>r;
		for (i=2;i<=16;i++){
			if (isBig(a,i)==true && isBig(b,i)==true && isBig(r,i)==true){
				int aa = change(a,i);
				int bb = change(b,i);
				int rr = change(r,i);
				long long ans = aa*bb;
				long long ans2 = rr;
				if (ans==ans2)
					break;
			}
			
		}
		if (i==17)
			i=0;
		cout<<i<<endl;
	}
	return 0;
}