/*
 * @file    :5_ProperRebuild.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-22
 * @brief   :Proper Rebuild
 *          :给定真二叉树（每个内部节点都有两个孩子的二叉树）的前序遍历和后序遍历
 *          :求中序遍历（真二叉树可由前序和后序遍历完全确定）
 */
#include <iostream>

using namespace std;

const int N = 4e6 + 6;
int n, pre[N], mid[N], post[N], t = 0; // 定义前中后遍历结果集

struct BTNode{
    int data;
    BTNode* left;
    BTNode* right;
    // BTNode():
    //     left(NULL), right(NULL) { }
    BTNode(int a, BTNode* left = NULL, BTNode* right = NULL): // 重构新结点
        data(a), left(left), right(right) { }
};

void rebuildBT(BTNode* root, int* pre, int* post, int n); // 重构二叉树
void midOrder(BTNode* root); // 写入中序遍历结果集
void display(int* a, int n); // 打印遍历序列结果

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++){
        cin >> post[i];
    }
    BTNode* root = new BTNode(pre[0]);
    rebuildBT(root, pre, post, n);
    midOrder(root);
    display(mid, n);
    return 0;
}

// 根据先序遍历和后序遍历递归重构二叉树
void rebuildBT(BTNode* root, int* pre, int* post, int n){ // 根节点指针， 线序数组指针， 后序数组指针， 数组长度
    if(n < 2){ // 小于两个节点不构成真二叉树，直接返回
        return;
    }
    int preright, postleft; // 定义先序遍历右子树和后序遍历左子树的结点下标
    for(int i = 0; i < n; i++){
        if(pre[i] == post[n-2]){ // post[n-2]为右子树的根节点
            preright = i; // 在先序遍历中，找到右子树根节点的位置，则右子树根节点的右边的都为他的后代
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(pre[1] == post[i]){ // pre[1]为左子树的根节点
            postleft = i; // 在后序遍历中，找到左子树根节点的位置，则左子树根节点的左边的都为他的后代
            break;
        }
    }
    root->left = new BTNode(pre[1]); // 指向左子树
    root->right = new BTNode(post[n-2]); // 指向右子树
    rebuildBT(root->left, pre + 1, post, preright - 1); // 递归重构左子树
    rebuildBT(root->right, pre + preright, post + postleft + 1, n - postleft - 2); // 递归重构右子树
}

// 写入中序遍历结果集
void midOrder(BTNode* root){
    if(root == nullptr){ // 树为空，返回
        return;
    }
    midOrder(root->left);
    mid[t] = root->data;
    t++;
    midOrder(root->right);
}

// 打印遍历序列结果
void display(int* a, int n){ 
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}


//本题的逻辑结构：顺序表/二叉树
//本题的存储结构：链式
//解题思路和算法：根据先序遍历和后序遍历递归重构二叉树，对二叉树中序遍历，打印中序遍历序列
//效率：  时间复杂度：O(n^2)
//        空间复杂度：O(n)
/*测试数据：
输入：
5
1 2 4 5 3
4 5 2 3 1

-------------------------
输出：
4 2 5 1 3

*/