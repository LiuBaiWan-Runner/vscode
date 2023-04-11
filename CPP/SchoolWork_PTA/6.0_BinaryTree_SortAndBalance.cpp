#include <iostream> 
#include<stdlib.h>
using namespace std;

typedef struct BitNode{
   int data;
   struct BitNode *lchild;
   struct BitNode *rchild; 
}BitNode, *BiTree;

typedef struct treeNode{
    int data;
    int depth;
    struct treeNode *l;
	struct treeNode *r;
}treeNode, *tree;

bool search(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
	{
		*p=f;
		return false;
	}
	else if(T->data==key)
	{
		*p=T;
		return true;
	}
	else if(T->data>key)
		return search(T->lchild,key,T,p);
	return search(T->rchild,key,T,p);	
}
 
void Insert(BiTree *T,int key)
{
	BiTree p,s;
	if(!search(*T,key,NULL,&p))
	{
		s=new BitNode;
		s->data=key;
		s->lchild=s->rchild=NULL;
	if(!p)
		*T=s;
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
	} 
	else
		cout<<"not find"<<endl;
}

int BSTSearch(BiTree T,int x)
{
    BiTree p;
	int i=0;
    if(T!=NULL)
    {
        p=T;
        while(p!=NULL)
        {
			i++;
            if(p->data==x)
                return i;
            else if(x<p->data)
                p=p->lchild;
            else
                p=p->rchild;
        }
    }
    return 0;
}

int BSTSearch_2(tree T,int x)
{
    tree p;
	int i=0;
    if(T!=NULL)
    {
        p=T;
        while(p!=NULL)
        {
			i++;
            if(p->data==x)
                return i;
            else if(x<p->data)
                p=p->l;
            else
                p=p->r;
        }
    }
    return 0;
}



int max(int a,int b)
{
    return a>b ? a:b;
}

int deep(tree t)
{
    if(t==NULL)
    {
        return -1;
    }
    else
    {
        return t->depth;
    }
}



tree LL(tree t)
{
    tree p=t->l;
    t->l=p->r;
    p->r=t;
    t->depth=max(deep(t->l),deep(t->r))+1;
    p->depth=max(deep(p->l),deep(t->r))+1;
    return p;
}
tree RR(tree t)
{
    tree p=t->r;
    t->r=p->l;
    p->l=t;
    t->depth=max(deep(t->l),deep(t->r))+1;
    p->depth=max(deep(p->l),deep(t->r))+1;
    return p;
}
tree  LR(tree t)
{
    t->l=RR(t->l);//先做左旋
    return LL(t);//再做右旋
}
tree  RL(tree t)
{
    t->r=LL(t->r);//先做右旋
    return RR(t);//再做左旋
}



tree  creat(tree t,int x)
{
    if(t==NULL)
    {
        t=(tree)malloc(sizeof(tree));
        t->data=x;
        t->depth=0;
        t->l=t->r=NULL;
    }
    else if(x<t->data)
    {
        t->l=creat(t->l,x);
        if(deep(t->l)-deep(t->r)>1)//如果左子树和右子树之差大于1，则需要进行操作
        {
            if(t->l->data>x)
            {
                t=LL(t);
            }
            else
            {
                t=LR(t);
            }
        }
    }
    else if(x>t->data)
    {
        t->r=creat(t->r,x);
        if(deep(t->r)-deep(t->l)>1)//如果右子树和左子树之差大于1，则需要进行操作
        {
            if(t->r->data>x)
            {
                t=RL(t);
            }
            else
            {
                t=RR(t);
            }
        }
    }
    t->depth=max(deep(t->l),deep(t->r))+1;//注意这里要更新深度
    return t;
}

int main()
{
	BiTree T=NULL; 
	int BST_ASL=0,AVL_ASL=0;
	int n;
	cin>>n;
	int a[n];
	char c;
	for(int i=0;i<n;i++)
	{
		if(i<n-1){
			cin>>a[i]>>c;
		}
		else{
			cin>>a[i];
		}
		Insert(&T,a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		BST_ASL+=BSTSearch(T,a[i]);
	}
	cout<<"BST-ASL:"<<BST_ASL<<endl;

	//平衡二叉树
	tree t = NULL;
	for(int i=0; i<n; i++){
		t=creat(t,a[i]);
	}

	for(int i=0;i<n;i++)
	{
		AVL_ASL+=BSTSearch_2(t,a[i]);
	}
	cout<<"AVL-ASL:"<<AVL_ASL<<endl;
	return 0;
}