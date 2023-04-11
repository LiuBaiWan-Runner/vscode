/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/KJBU2/article/details/42638975
 *          :
 *          :
 */

#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int maxn=768;
int A[maxn],B[maxn];
struct Item{
    int s,b;
    Item(int s,int b):s(s),b(b){}
    bool operator<(const Item & C)const
    {
        return s>C.s;
    }
};
void merge()
{
    priority_queue<Item> q;
    for(int i=0;i<n;i++){
        q.push(Item(A[i]+B[0],0));
    }
 
    for(int i=0;i<n;i++){
        Item item=q.top();
        q.pop();
        A[i]=item.s;
        int b=item.b;
        if(b+1<n)q.push(Item(item.s-B[b]+B[b+1],b+1));
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(i==0) scanf("%d",&A[j]);
                else scanf("%d",&B[j]);
            if(i==0) sort(A,A+n);
            else sort(B,B+n);
            if(i>0)
                merge();
        }
        for(int i=0;i<n;i++)
            printf("%d%c",A[i],i==n-1?'\n':' ');
 
    }
    return 0;
}