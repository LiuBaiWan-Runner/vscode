  /*
  * @file    :9_copy_2.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-08
  * @brief   :后缀表达式求值
  *          :https://blog.51cto.com/u_14691718/3332078
  *          :
  */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int stack[101];
char s[256];
int comp(char s[256])
{
	int i=0,top=0,x,y;
	while(i<=strlen(s)-2)
	{
		switch(s[i])
		{
			case '+':
				stack[--top]+=stack[top+1];break;
			case '-':
				stack[--top]-=stack[top+1];break;
			case '*':
				stack[--top]*=stack[top+1];break;
			case '/':
				stack[--top]/=stack[top+1];break;
			default:
				x=0;
				while(s[i]!=' ')
				x=x*10+s[i++]-'0';
				stack[++top]=x;
				break;
		}
		i++;
	}
	return stack[top];
}
int main ()
{
	printf("input a string (@_over):");
	gets(s);
	printf("result=%d",comp(s));
	return 0;
}
