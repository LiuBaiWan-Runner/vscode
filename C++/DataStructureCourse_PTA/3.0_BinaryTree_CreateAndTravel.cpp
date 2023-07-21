#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct BinTree_Node 
{
	char value;                // 节点的值 
	BinTree_Node* lChild;   // 左子节点 
	BinTree_Node* rChild;   // 右子节点 
	// 节点的构造函数 
	BinTree_Node(): lChild(NULL), rChild(NULL)
	{
	}
};

typedef BinTree_Node* BT_Node; 

// 创建二叉树 (先序遍历)
BT_Node Create_BinTree()
{
	BT_Node root = new BinTree_Node();
	char v;
	cin >> v;
	if (v != '#')
	{
		root->value = v;
		root->lChild = Create_BinTree();
		root->rChild = Create_BinTree();
	}
	else
		root = NULL; 
	return root;
}

//先序遍历 ————  左子树-根节点-右子树  简称：根左右
void Pre_Traverse(BT_Node root)
{
	if (root == NULL)    // 递归出口
		return;
	
	cout << root->value;
	Pre_Traverse(root->lChild);
	Pre_Traverse(root->rChild);	
}

// 中序遍历  ————  左根右
void In_Traverse(BT_Node root)
{
	if (root == NULL)    // 递归出口
		return;
	
	In_Traverse(root->lChild);
	cout << root->value;
	In_Traverse(root->rChild);
 } 
 
// 后序遍历 ————  左右根
void Post_Traverse(BT_Node root)
{
	if (root == NULL)    // 递归出口
		return;
	
	Post_Traverse(root->lChild);
	Post_Traverse(root->rChild);
	cout << root->value;
}

vector<vector<int>> Level_Traverse(BT_Node root) 
{
	vector<vector<int>> res;
	if (!root)
	{
		return res;
	}
	vector<int> temp;
	queue<BT_Node> qu;
	BT_Node cur;
	int len = 1;
	qu.push(root);
	while (!qu.empty())
	{
		for (int i = 0; i < len; ++i)
		{
			cur = qu.front();
			temp.push_back(cur->value);
			cout << cur->value;
			qu.pop();
			if (cur->lChild)
			{
				qu.push(cur->lChild);
			}
			if (cur->rChild)
			{
				qu.push(cur->rChild);
			}
		}
		if(!qu.empty())
		cout << endl;
		res.push_back(temp);
		temp.clear();
		len = qu.size();
	}
	return res;
}

//递归 由上自下寻找叶子结点，遍历到最底部逐层往上汇报
int GetLeafNodeNum(BT_Node root)
{
    if(root == NULL)
		return 0; //空树返回0 
    else if(root->lChild == NULL && root->rChild ==NULL)
    	return 1; //左右子树为空是叶子结点，返回1  
    return GetLeafNodeNum(root->lChild) + GetLeafNodeNum(root->rChild);  //返回左右子树的叶子结点和 
}


int GetHeight( BT_Node root )
{
    if(root==NULL)return 0;
    int x,y;
    x=GetHeight(root->lChild)+1;
    y=GetHeight(root->rChild)+1;
    return x>y?x:y;
}


int main()
{
    int n;
    cin>>n;
	BT_Node root;
	root = Create_BinTree();
	cout<<"preorder traversal:";
    Pre_Traverse(root);
    cout<<endl<<"inorder traversal:";
	In_Traverse(root);
    cout<<endl<<"postorder traversal:";
    Post_Traverse(root);
    cout<<endl;
	cout<<"level traversal:"<<endl;
	Level_Traverse(root);
    cout<<endl;
    cout<<GetLeafNodeNum(root);
	cout<<endl;
	cout<<GetHeight(root);
} 
