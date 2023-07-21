#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef char Excel;
typedef struct Node
{
	float coefficient;
	int power;
	struct Node *next;
} LNode,*LinkList;

typedef struct
{
	Excel name[100];
	int length;
	LinkList next;
} HeadList,*HeadLinkList;

//函数声明
LinkList Init(int *n); //初始化链表体
HeadLinkList HeadInit(char a[]);//初始化链表头
LinkList Find(LinkList Head,int s);//查找链表中第一个系数大于ans的结点的前驱
void Add(HeadLinkList A,HeadLinkList B,HeadLinkList C);//加法
void Sub(HeadLinkList A,HeadLinkList B,HeadLinkList C);//减法
void Mul(HeadLinkList A,HeadLinkList B,HeadLinkList C);//乘法
void Free(HeadLinkList Head);//释放链表体内存
void Display(HeadLinkList Head);//将链表数据域以多项式形势输出
void Calculation(HeadLinkList Head,float a);//代入计算


int main()
{
	float x;
	HeadLinkList A,B,C;
	A=HeadInit("A polynomial");
	A->next=Init(&A->length);
	B=HeadInit("B polynomial");
	B->next=Init(&B->length);
	C=HeadInit("C polynomial");
	C->next=NULL;
	scanf("%f",&x);
	printf("f(x)=");
	Display(A);
	printf("g(x)=");
	Display(B);
	Add(A,B,C);
	printf("f(x)+g(x)=");
	Display(C);
	Sub(A,B,C);
	printf("f(x)-g(x)=");
	Display(C);
	Mul(A,B,C);
	printf("f(x)*g(x)=");
	Display(C);
	printf("f(%.1f)=",x);
	Calculation(A,x);
	Free(A);
	Free(B);
	Free(C);
	free(A),free(B),free(C);
	return 0;

}

//查找链表中第一个系数大于s的结点的前驱
LinkList Find(LinkList Head,int s)
{
	if(Head->next == NULL || Head->next->power < s)
		return Head;
	return Find(Head->next,s);
}

//初始化链表头
HeadLinkList HeadInit(char *a)
{
	HeadLinkList Head;
	Head=(HeadLinkList)malloc(sizeof(HeadList));
	strcpy(Head->name,a);
	Head->length=0;
	return Head;
}

//初始化链表体
LinkList Init(int *n)
{
	LinkList Head,p,q;
	float a;
	int b;
	Head=NULL;
	while(~scanf("%f,%d",&a,&b) && a!=0)
	{
		q=(LinkList)malloc(sizeof(LNode));
		q->coefficient=a;
		q->power=b;
		if(*n==0 || Head->power<b)
		{
			q->next=Head;
			Head=q;
		}
		else
		{
			p=Find(Head,b);
			q->next=p->next;
			p->next=q;
		}
		(*n)++;
	}
	return Head;
}


//多项式加法 O(n)
void Add(HeadLinkList A,HeadLinkList B,HeadLinkList C)
{
	LinkList qa=A->next,qb=B->next,p,q=NULL;
	Free(C);
	while(qa || qb)
	{
		p=(LinkList)malloc(sizeof(LNode));
		if(qb==NULL || qa && qa->power<qb->power)
		{
			*p=*qa;
			qa=qa->next;
		}
		else if(qa==NULL || qb && qa->power>qb->power)
		{
			*p=*qb;
			qb=qb->next;
		}
		else
		{
			p->coefficient=qb->coefficient+qa->coefficient;
			p->power=qb->power;
			qa=qa->next;
			qb=qb->next;
		}
		if(q==NULL) p->next=q,C->next=q=p;
		else
			p->next=q->next,q->next=p,q=p;
		    C->length++;
	}
}

//多项式减法 O(n)
void Sub(HeadLinkList A,HeadLinkList B,HeadLinkList C)
{
	LinkList qa=A->next,qb=B->next,p,q=NULL;
	Free(C);
	while(qa!=NULL || qb!=NULL)
	{
		p=(LinkList)malloc(sizeof(LNode));
		if(qb==NULL || qa && qa->power<qb->power)
		{
			*p=*qa;
			qa=qa->next;
		}
		else if(qa==NULL || qb && qa->power>qb->power)
		{
			*p=*qb;
			p->coefficient*=-1;
			qb=qb->next;
		}
		else
		{
			*p=*qa;
			p->coefficient-=qb->coefficient;
			qa=qa->next;
			qb=qb->next;
			if(p->coefficient==0)
			{
				free(p);
				continue;
			}
		}
		if(q==NULL) p->next=q,C->next=q=p;
		else
			q->next=p->next,q->next=p,q=p;
		    C->length++;
	}
}

//多项式乘法 O(n^3)
void Mul(HeadLinkList A,HeadLinkList B,HeadLinkList C)
{
	LinkList qa,qb,p,q;
	int a,b;
	Free(C);
	for(qa=A->next; qa; qa=qa->next)
	{
		for(qb=B->next; qb; qb=qb->next)
		{
			a=qa->coefficient*qb->coefficient;
			b=qa->power+qb->power;
			if(C->length)
			{
				p=Find(C->next,b);
				if(p->power== b)
					p->coefficient+=a;
				else
				{
					q=(LinkList)malloc(sizeof(LNode));
					q->coefficient=a;
					q->power=b;
					q->next=p->next;
					p->next=q;
					C->length++;
				}
			}
			else
			{
				p=(LinkList)malloc(sizeof(LNode));
				p->coefficient=a;
				p->power=b;
				p->next=C->next;
				C->next=p;
				C->length++;
			}
		}
	}
}

//释放链表体内存
void Free(HeadLinkList Head)
{
	LinkList q=Head->next,p;
	while (q)
	{
		p=q;
		q=q->next;
		free(p);
	}
	Head->length=0;
	Head->next=NULL;
	return ;
}

//将链表数据域以多项式形势输出
void Display(HeadLinkList Head)
{
	LinkList q=Head->next;
	while(q)
	{
		if(q!=Head->next && q->coefficient>0)
			printf("+");
		if(q->coefficient!=0 && q->power!=1 && q->power!=0)
		{
			if(q->coefficient==1)
				printf("X^%.1d",q->power);
			else
				printf("%.1fX^%.1d",q->coefficient,q->power);
		}
		else if(q->coefficient!=0 && q->power==1)
		{
			if(q->coefficient==1)
				printf("X");
			else if(q->coefficient==-1)
				printf("-X");
			else
				printf("%.1fX",q->coefficient);
		}
		else if(q->coefficient!=0 && q->power==0)
			printf("%.1f",q->coefficient);
		q=q->next;
	}
	printf("\n");
	return ;
}
//代入计算
void Calculation(HeadLinkList Head,float a)
{
	LinkList q=Head->next;
	float n=0;
	while(q)
	{
		n+=q->coefficient*pow(a,q->power);
		q=q->next;
	}
	free(q);
	printf("%.1f",n);
}