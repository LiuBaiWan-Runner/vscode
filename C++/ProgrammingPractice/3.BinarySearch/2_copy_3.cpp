/*
* @file    :2_copy_3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :POJ 2503 Babelfish（map）
*          :https://blog.csdn.net/weixin_43838723/article/details/106600598
*          :
*/
#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
 
map<string,string> dic;//map字典 
 
int main()
{
	char pre[12],suf[12],str[24];//定义键值对字符数组和输入所需要的变量
	while(gets(str)&&str[0]!='\0'){
		sscanf(str,"%s %s",suf,pre);//按序读取str，注意中间的空格以及sscanf用法 
		dic[pre]=suf;
	}
	while(gets(str)&&str[0]!='\0'){
		if(dic.count(str))  cout<<dic[str]<<endl;
		else  cout<<"eh"<<endl;		
	}
	return 0;
}