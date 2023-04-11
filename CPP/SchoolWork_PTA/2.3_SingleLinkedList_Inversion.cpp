#include<cstdio>
 
struct Node
{
	int data;
	Node* next;
};
 
void reverse(Node* first)
{
	Node *p, *q;
	p = first->next;
	first->next = NULL;
	while(p!=NULL)
	{
		q = p->next;
		p->next = first->next;
		first->next = p;
		p = q;
	}
}
 
void print_node(Node *first)
{
	Node *p = first->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
		if(p != NULL)
			printf(" ");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	//构建单链表
	Node *first = new Node;
	first->next = NULL;
	Node *r = first;
	for (int i = 0; i < n; i++)
	{
		Node *p = new Node;
		scanf("%d", &p->data);
		p->next = NULL;
		r->next = p;
		r = p;
	}
	reverse(first);
	print_node(first);

	//析构
	while (first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
	}
	return 0;
}