/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-01
* @brief   :上海计算机学会2023年1月月赛C++丙组T3区间的并
*          :参考：https://blog.csdn.net/qq_36230375/article/details/129128102
*          :
*/
#include<bits/stdc++.h>
using namespace std;
struct st//定义结构体表示区间
{
    int a;
    int b;
};
struct st s[100005];

bool cmp(struct st x,struct st y)//自定义排序比较函数
{
    if (x.a==y.a) return x.b<y.b;//如果区间起始点相同，终止点小的排在前边
    return x.a<y.a;//起始点小的排在前边
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].b;
    }
    sort(s+1,s+n+1,cmp);//排序
    
    int l,r;//当前区间的起始点和终止点
    l=s[1].a;
    r=s[1].b;
    for (int i=2;i<=n;i++)
    {
        if (s[i].a<=r)//能合并的情况
        {
            r=max(s[i].b,r);           //题解没有考虑这一点
        }else//不能合并的情况
        {
            cout<<l<<" "<<r<<endl;
            l=s[i].a;
            r=s[i].b;
        }
    }
    cout<<l<<" "<<r<<endl;//输出最后一个合并后的区间
    return 0;
}