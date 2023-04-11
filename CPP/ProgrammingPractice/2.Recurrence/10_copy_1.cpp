/*
* @file    :10_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :左右括号匹配
*          :https://blog.csdn.net/lybc2019/article/details/104147232
*          :
*/
#include<stdio.h>
#include<iostream> 
#include<cstring>
using namespace std;
char a[101],b[101];
int up(int c)
{
	if(c==-1) return -1;//结束点 
	else if(b[c]=='$') return c;//找到返回位置 
	else return up(c-1);//向前寻找 
}
int main()
{
	while(scanf("%s",a)!=-1){//重复读取直到读取失败 
		printf("%s\n",a);
		int n=strlen(a);
		memset(b,' ',sizeof(b));//初始化为空格 
		for(int i=0;i<n;i++){
			if(a[i]=='(') b[i]='$';//'('标记 
			else if(a[i]==')'){
				int m=up(i-1);//寻找对应位置点 
				if(m==-1) b[i]='?';//无匹配 标记位置点 
				else b[m]=' ';//有匹配 取消标记 
			} 
		}
		printf("%s\n",b);
	}
	return 0;
} 