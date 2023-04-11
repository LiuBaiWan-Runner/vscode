#include <iostream>
using namespace std;

int MAXSIZE;
// 二叉树存储结点
struct BiNode {
	char data;
	BiNode *lchild, *rchild;
};

typedef BiNode* BiTree;

// 构造二叉树
void CreateBiTree(BiTree &T) {
	char ch;
	std::cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

// 删除二叉树
void DeleteBiTree(BiTree &T) {
	if (T == NULL)
		return;
	else {
		DeleteBiTree(T->lchild);
		DeleteBiTree(T->rchild);
		delete T;
	}
}

// 队列结点
struct SqQueue {
	BiTree* data;
	int front, rear;
};

// 队列初始化
int InitQueue(SqQueue &Q) {
	Q.data = new BiTree[MAXSIZE];
	Q.front = Q.rear = 0;
	return 1;
}

// 入队
int EnQueue(SqQueue &Q, BiTree e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return 0;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}

// 出队
int DeQueue(SqQueue &Q, BiTree &e) {
	if (Q.front == Q.rear)
		return 0;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}

// 判断队空
bool QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear)
		return 1;
	return 0;
}

// 删除队列
int DeleteQueue(SqQueue &Q) {
	delete[] Q.data;
	Q.front = Q.rear = 0;
	return 1;
}

// 二叉树的最大宽度计算
int WidthCount(BiTree &T) {
	BiNode *p;
	SqQueue qu;
	InitQueue(qu);
	EnQueue(qu, T);
	int width = 0;
	int last = 1;
	int max = 1;
	while (!QueueEmpty(qu)) {
		DeQueue(qu, p);
		if (p->lchild != NULL) {
			EnQueue(qu, p->lchild);
			width++;
		}
		if (p->rchild != NULL) {
			EnQueue(qu, p->rchild);
			width++;
		}
		if (--last == 0) {
			last = width;
			if (max < width) {
				max = width;
			}
			width = 0;
		}
	}
	DeleteQueue(qu);
	return max;
}

// main函数
int main()
{
	cin>>MAXSIZE;
	BiTree bt;
	CreateBiTree(bt);
	cout  << WidthCount(bt) << endl;
	DeleteBiTree(bt);
}
