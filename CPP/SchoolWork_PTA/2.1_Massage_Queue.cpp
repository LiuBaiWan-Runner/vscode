#include<cstdio>
#include<queue>
#include<string.h> 
using namespace std;

struct node
{
	int pri;
	char s[15];
	bool operator <(const node&a) const
	{
		return pri>a.pri;
	}
};

priority_queue <node> q;
int main()
{
	int n,t;
	char a[15],b[15];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		if(a[0]=='P')
		{
			scanf("%s%d",b,&t);
			struct node x;
			x.pri=t;
			strcpy(x.s,b);
            q.push(x); 
		}
		else if(q.empty())
		{
			printf("EMPTY QUEUE!\n");
		}
		else
		{
			node x=q.top();
			q.pop();
			printf("%s\n",x.s);
		}
	} 
 	return 0;
}