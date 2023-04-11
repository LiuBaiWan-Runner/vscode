
/*
 * @file    :7.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/qq_18455665/article/details/50285203
 *          :
 *          :
 */
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 205
#define M 10005
int n,x,l;
int a[N],ans[N];
int f[M];
int calc(int x,int v){
    if(x<0) return 0;
    else return f[x]-calc(x-v,v);
}
int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=x;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    for(int i=1;i<=n;i++){
        if(!(f[x]-calc(x-a[i],a[i]))){
            ans[++l]=a[i];
        }
    }
    printf("%d\n",l);
    for(int i=1;i<=l;i++) printf("%d ",ans[i]);
    return 0;
}