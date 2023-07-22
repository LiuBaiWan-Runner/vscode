#include <iostream>
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
 
int main(int argc, const char * argv[]) {
    Stack s; // 声明对象，等价于 struct Stack s
    int val, choose, len; // val存储值，choose存储用户的选择
    bool finished = false;
    
    while(!finished) {
        cout << "1:初始化栈：" << endl;
        cout << "2:建栈(以-1结束输入)：" << endl;
        cout << "3:遍历栈：" << endl;
        cout << "4:压栈：" << endl;
        cout << "5:出栈：" << endl;
        cout << "6:取栈顶的元素值：" << endl;
        cout << "7:栈是否为空：" << endl;
        cout << "8:获取栈的长度：" << endl;
        cout << "9:退出：" << endl;
        cout << "请输入你的选择[1-9]：" << endl;
        cin >> choose;
        switch(choose) {
            case 1:
                Init(&s); // 初始化栈
                break;
            case 2:
                CreateStack(&s); // 建栈
                break;
            case 3:
                cout << "栈中的元素为：" << endl;
                Travers(&s); // 遍历栈
                break;
            case 4:
                cout << "请输入要压入栈中的元素值:" << endl;
                cin >> val;
                Push(&s, val);
                break;
            case 5:
                if(Pop(&s)) // 出栈
                    cout << "出栈成功！" << endl;
                else
                    cout << "出栈失败！" << endl;
                break;
            case 6:
                if(getTop(&s, val))
                    cout << "栈顶元素的值为：" << val << endl;
                else
                    cout << "栈为空！" << endl;
                break;
            case 7:
                if(isEmpty(&s))
                    cout << "栈为空!" << endl;
                else
                    cout << "栈不空" << endl;
                break;
            case 8:
                len = getSize(&s);
                cout << "栈的长度为：" << len << endl;
                break;
            case 9:
                finished = true;
                break;
            default:
                cout << "输入选择错误，请重新输入!" << endl;
        }
    }
    return 0;
}
 
// 初始化
void Init(Stack *pS) {
    pS->pTop = new Node();
    if(NULL == pS->pTop) {
        cerr << "动态内存分配失败！" << endl;
        exit(1);
    }
    pS->pBottom = pS->pTop; // 顶部指针和底部指针指向同一个位置
    pS->pTop->next = NULL; // pS->pBottom->next = NULL;
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
    int len = 0;
    Node *p = pS->pTop;
    while(p != pS->pBottom) {
        len++;
        p = p->next;
    }
    return len;
}