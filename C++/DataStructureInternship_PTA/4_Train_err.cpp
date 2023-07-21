/*
 * @file    :4_Train.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :Train
 *          :自己实现链表栈
 *          :
 */
#include <iostream>
#include <stack>
using namespace std;

// 结点结构体
struct Node {
    int data;
    Node *next;
};
 
// 栈
struct Stack {
    Node *pTop; // 顶部指针
    Node *pBottom; // 底部指针
};
 
void Init(Stack *pS); // 初始化
void CreateStack(Stack *pS); // 建栈
void Travers(Stack *pS); // 遍历栈
void Push(Stack *pS, int val); // 压栈
bool Pop(Stack *pS); // 出栈：把栈顶的结点删掉
bool getTop(Stack *pS, int &val); // 获取栈顶元素：但不删除栈顶结点
bool isEmpty(Stack *pS); // 判断栈是否为空
int getSize(Stack *pS); // 获取栈的长度


// 初始化
void Init(Stack *pS) {
    pS->pBottom = new Node();
    if(NULL == pS->pBottom) {
        cerr << "动态内存分配失败！" << endl;
        exit(1);
    }
    pS->pTop = pS->pBottom; // 顶部指针和底部指针指向同一个位置
    pS->pTop->next = NULL; // pS->pBottom->next = NULL;
    pS->pTop->data = 0;
}
 
// 建栈
void CreateStack(Stack *pS) {
    int val;
    cout << "请输入各个元素值：" << endl;
    
    while(cin >> val && val != -1)
        Push(pS, val);
}
 
// 压栈
void Push(Stack *pS, int val) {
    Node *newNode = new Node(); // 新建结点
    if(NULL == newNode) {
        cerr << "动态内存分配失败！" << endl;
        exit(1);
    }
    newNode->data = val;
    newNode->next = pS->pTop;
    pS->pTop = newNode; // 顶端指针往上移
}
 
// 遍历栈
void Travers(Stack *pS) {
    Node *p = pS->pTop;
    
    while(p != pS->pBottom) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
 
// 判断栈是否为空：通过比较栈顶和栈尾指针是否相等，如相等，说明为空
bool isEmpty(Stack *pS) {
    if(pS->pTop == pS->pBottom)
        return true;
    return false;
}
 
// 出栈：把栈顶的结点删掉
bool Pop(Stack *pS) {
    if(isEmpty(pS))
        return false;
    Node *r = pS->pTop; // 暂存顶指针
    pS->pTop = r->next; // 栈顶指针往下移一个结点
    delete r; // 释放空间
    r = NULL; // 指向空
    return true;
}
 
// 获取栈顶元素：但不删除栈顶结点
bool getTop(Stack *pS, int &val) {
    if(isEmpty(pS)) // 栈空，返回0
        return false;
    val = pS->pTop->data;
    return true; // 否则返回栈顶的元素值
}
 
// 获取栈的长度
int getSize(Stack *pS) {
    Node *p = pS->pTop;
    int len = 0;
    while(p != pS->pBottom) {
        len++;
        p = p->next;
    }
    return len;
}

int main(){
    int n, m, x, val = 0, now = 1, t = 0;
    cin>>n>>m;
    Stack st;
    Init(&st);
    int a[n];
    for(int i=0; i<n; i++){
        cin>>x;
        while(now <= x){
            Push(&st, now);
            now++;
            a[t] = 0;
            t++;
        }
        if(getSize(&st) > m){
            cout<<"No"<<endl;
            return 0;
        }
        getTop(&st, val);
        if(val == x){
            Pop(&st);
            a[t] = 1;
            t++;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=0; i<t; i++){
        if(a[i] == 0){
            cout << "push" << endl;
        }
        else{
            cout << "pop" << endl;
        }
    }
    return 0;
}