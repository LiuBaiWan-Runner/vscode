https://blog.csdn.net/c20190102/article/details/52350828

#include<cstdio>
#include<cstring>
char s[12];
int main()
{
	int n;
	scanf("%d",&n);
	for(int q=0;q<n;q++)
	{
		int k;
		scanf("%s",s);
		scanf("%d",&k);
		int len=strlen(s); 
		while(k--)//当k为零时，表示数已删够k位，跳出循环
		{
			for(int i=0;i<len;i++)
				if(s[i]>s[i+1])
				{
					for(int j=i;j<len;j++)
						s[j]=s[j+1];
					break;//当一个“山峰”删过之后记得break，否则……自己试试吧
				}
			len--;//既然删了一个数，长度肯定要减少
		}
		while(s[0]=='0')//删除前导0（我方法很笨，不要在意）
		{
			for(int i=0;i<len;i++)
				s[i]=s[i+1];
			len--;
		}
		if(s[0]==0)//处理删到没有（全是“\0”）的情况
			printf("0\n");
		else
			printf("%s\n",s);
	}
	return 0;
}