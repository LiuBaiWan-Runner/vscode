#include<bits/stdc++.h>
using namespace std;
//定义二叉树
struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
    treeNode() :
		left(NULL), right(NULL) { }
	treeNode(int e, treeNode* left = NULL, treeNode* right = NULL) :
		data(e), left(left), right(right) { }
};

//根据先序遍历和后序遍历重构二叉树
void rebuild(treeNode* root, int* pre, int* post, int n)
{
    if(n < 2){
        return;
    }
    int postleft,preright;  //定义后序遍历左子树和先序遍历的右子树根节点下标
    for(int i=0; i<n; i++){
        if(pre[i] == post[n-2]){
            preright = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(pre[1] == post[i]){
            postleft = i;
            break;
        }
    }
    root->left = new treeNode(pre[1]);
    root->right = new treeNode(post[n-2]);
    //对左右子树递归重构
    rebuild(root->left, pre+1, post, preright-1);
    rebuild(root->right, pre+preright, post+postleft+1, n-postleft-2);
}

//二叉树中序遍历
void inorder(treeNode* root)
{
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cin>>n;
    int *pre = new int[n+10];
    int *post = new int[n+10];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    for(int i=0; i<n; i++){
        cin>>post[i];
    }
    treeNode* root = new treeNode(pre[0]);
    rebuild(root, pre, post, n);
    inorder(root);
    return 0;
}
