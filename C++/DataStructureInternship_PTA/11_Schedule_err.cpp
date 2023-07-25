/*
 * @file    :11_Schedule_err.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-24
 * @brief   :Schedule
 *          :
 *          :
 */
#include <iostream>

using namespace std;

#define MinData -1//哨兵元素的值
#define ll long long

struct Node{
    ll v;
    string name;
};

typedef struct HeapStruct{
    Node* p;
    int size;
    int capacity;
}* MinHeap;

const int N = 4e6 + 10;
int n,m;

MinHeap Init_MinHeap(int MaxSize);
int IsFull(MinHeap H);
int IsEmpty(MinHeap H);
// void Insert(MinHeap H, int value);
void Insert(MinHeap H, int value, string name);
// int Delete(MinHeap H);
Node Delete(MinHeap H);
void BuildMinHeap(MinHeap H, int N);
void PrintValue(MinHeap H);

int main(){
    cin>>n>>m;
    Node top;
    MinHeap H;
    H = Init_MinHeap(N);
    BuildMinHeap(H, n);
    // PrintValue(H);

    for(int i=0; i<m; i++){
        if(!IsEmpty(H)){
            top = Delete(H);
            cout << top.name << endl;
            Node tmp = top;
            tmp.v = top.v * 2;
            Insert(H, tmp.v, tmp.name);
            // PrintValue(H);
        }
    }
    return 0;
}

int IsFull(MinHeap H)
{
    return (H->size == H->capacity) ? 1 : 0;
}

int IsEmpty(MinHeap H)
{
    return (H->size == 0) ? 1 : 0;
}

void PrintValue(MinHeap H)
{
    int i;
    printf("最小堆中的元素依次为：\n");
    for (i = 1; i <= H->size; i++)
        // printf("%d ", H->p[i]);
        cout << H->p[i].v << ' ' << H->p[i].name << endl;
    // printf("\n");
}

MinHeap Init_MinHeap(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(HeapStruct));
    // H->p = (int*)malloc((MaxSize + 1) * sizeof(int));
    H->p = (Node*)malloc((MaxSize + 1) * sizeof(Node));
    H->p[0].v = MinData;
    H->size = 0;
    H->capacity = MaxSize;
    return H;
}

void Insert(MinHeap H, int value, string name)
{
    int i;
    if (IsFull(H))
    {
        printf("最小堆已满，无法插入元素");
        return;
    }
    for (i = ++H->size; value < H->p[i / 2].v; i /= 2)
        H->p[i].v = H->p[i / 2].v;
    H->p[i].v = value;
    H->p[i].name = name;
}

Node Delete(MinHeap H)
{
    // int minvalue , lastvalue, child, parent;
    int lastvalue, child, parent;
    string lastname;
    Node del;
    if (IsEmpty(H))
    {
        printf("最小堆已空，无法删除元素");
        return del;
    }

    // minvalue = H->p[1].v;
    del = H->p[1];
    lastvalue = H->p[H->size--].v;
    lastname = H->p[H->size--].name;
    for (parent = 1; 2 * parent <= H->size; parent = child)
    {
        child = 2 * parent;/*默认左结点的元素值更小*/
        if (child != H->size && H->p[child + 1].v < H->p[child].v)/*若右节点的元素值更小，则调整child*/
            child++;
        if (lastvalue < H->p[child].v)
            break;
        else
            H->p[parent].v = H->p[child].v;
    }
    H->p[parent].v = lastvalue;
    H->p[parent].name = lastname;
    // return minvalue;
    return del;
}


void BuildMinHeap(MinHeap H, int n)
{
    // int i, num, parent, child, root, lastvalue;
    int i, thisvalue, parent, child, root, lastvalue;
    string thisname;
    if (n > H->capacity)
    {
        printf("要创建的元素个数超过堆的最大容量，创建失败");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        // printf("请输入要插入的元素值:");
        // scanf("%d", &num);
        cin >> thisvalue >> thisname;
        H->p[i].v = thisvalue;
        H->p[i].name = thisname;
    }
    H->size = n;

    root = n / 2;/*从第N/2个结点到第1个结点依次进行下滤 近似N/2次删除操作*/
    while (root)
    {
        lastvalue = H->p[root].v;
        for (parent = root; 2 * parent <= H->size; parent = child)
        {
            child = 2 * parent;/*默认左结点的元素值更小*/
            if (child != H->size && H->p[child + 1].v < H->p[child].v)/*右结点元素值更小*/
                child++;
            if (lastvalue < H->p[child].v)
                break;
            else
                H->p[parent].v = H->p[child].v;
        }
        H->p[parent].v = lastvalue;
        --root;
    }
}
