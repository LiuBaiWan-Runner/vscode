/*
* @file    :9_copy_2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :UVA 10474 Where is the Marble? (STL最简单运用)
*          :https://blog.csdn.net/hurmishine/article/details/51429295
*          :
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn  10005
int main()
{
    int n,m;
    int a[maxn];
    int kase=0;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<"CASE# "<<++kase<<":"<<endl;
        while(m--)
        {
            int x;
            cin>>x;
 
            bool flag = false;
            int ans=0;
            for(int i=0;i<n;i++)
            {
                ans++;
                if(a[i]==x)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                cout<<x<<" found at "<<ans<<endl;
            else
                cout<<x<<" not found"<<endl;
        }
    }
    return 0;
}