/*
* @file    :5_copy_3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :24点游戏
*          :https://blog.csdn.net/qq_41661919/article/details/79574785
*          :
*/
#include<bits/stdc++.h>
using namespace std;
bool search(double a[],int x)  //数组作为实参，形参要多注意一下，多练习使用临时数组；
{
    if(x==1&&fabs(a[1]-24)<=1e-6)return 1;  //题目要求除法运算为实数；
    double b[6];        //数据量不大时尽量多练习使用临时数组；
    memset(b,0,sizeof(b));
    for(int i=1;i<=x-1;++i)
        for(int j=i+1;j<=x;++j)
        {
            int p=1;
            for(int k=1;k<=x;++k)
            {
                if(k!=i&&k!=j)
                {
                    b[p++]=a[k];
                }
            }
            b[p]=a[i]+a[j]; if(search(b,x-1))return 1;//分别递归，依次穷举；
            b[p]=a[i]*a[j]; if(search(b,x-1))return 1;//在这里错了一次，错误写法：return search(b,x-1);
            b[p]=a[i]-a[j]; if(search(b,x-1))return 1;
            b[p]=a[j]-a[i]; if(search(b,x-1))return 1;
            if(a[j]!=0)
            {
                b[p]=a[i]/a[j];
                if(search(b,x-1))return 1;
            }
            if(a[i]!=0)
            {
                b[p]=a[j]/a[i];
                if(search(b,x-1))return 1;
            }
        }
     return 0;
}
int main()
{
    while(1)
    {
        double a[6];
        memset(a,0,sizeof(a));
        int sum=0;
        for(int i=1;i<=4;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==0)break;
        bool flag=search(a,4);
        if(flag==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;  
        //cout<<flag<<endl;
    }
    return 0;
}