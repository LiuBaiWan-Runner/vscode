/*
 * @file    :7.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/Wanglinlin_bfcx/article/details/77925817
 *          :
 *          :
 */
#include<bits/stdc++.h>
using namespace std;
int i,a[100],n,l[100],r[100],b[100];
int main()
{
    cin>>n;
    if(n==1)
      cout<<3;
      else
      {
        l[1]=1;r[1]=1;b[1]=1;
        for(i=2;i<=n;i++)
           {
            l[i]=l[i-1]+b[i-1];
            r[i]=r[i-1]+b[i-1];
            b[i]=l[i-1]+b[i-1]+r[i-1];
             }
      }
      cout<<l[n]+r[n]+b[n]<<endl;
}