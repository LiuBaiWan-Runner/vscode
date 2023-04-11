/*
* @file    :10_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :左右括号匹配
*          :https://blog.csdn.net/lybc2019/article/details/104147232
*          :
*/
#include<cstdio>
#include<iostream> 
#include<cstring>
using namespace std;
int l,i,top,a[101],b[101];
string s;
int main()
{
	while(getline(cin,s)){//重复读取一行字符串 
		top=0;
		l=s.size();
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<l;i++){
			if(s[i]=='('){
				top++;
				a[top]=i;//遇'('入栈 
				b[i]=1;//标记 
			}
			if(s[i]==')'){
				b[i]=2;
				if(top>0){
					b[a[top]]=0;//取消'('标记
					b[i]=0;//取消')'标记
					top--;//出栈 
				}
			}
		}
		cout<<s<<endl;
		for(i=0;i<l;i++){
			if(b[i]==0) cout<<" ";
			if(b[i]==1) cout<<"$";
			if(b[i]==2) cout<<"?";
		}
		cout<<endl;
	}	
	return 0;
 } 