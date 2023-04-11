/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-08
 * @brief   :https://blog.csdn.net/tengfei461807914/article/details/55098672
 *          :
 *          :
 */

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int topic;
int sum[1001];
int L,C;
int solve(int tmp)
{
    int res=L-tmp;
    if(res==0)
        return 0;
    if(res<=10)
        return -C;
    return (res-10)*(res-10);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,t=0;
    while(cin>>n,n)
    {
        cin>>L>>C;
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            cin>>topic;
            sum[i]=topic+sum[i-1];
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dp[i][j]=INT_MAX;
            dp[i][0]=0;
        }
        for(int i=1;i<=n||dp[i-1][n]==INT_MAX;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(sum[j]>i*L)
                    break;
                for(int k=j;k>=i-1&&sum[j]-sum[k]<=L;k--)
                {
                    int res=sum[j]-sum[k];
                    if(res<=L&&dp[i-1][k]!=INT_MAX)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+solve(res));
                }
            }
        }
        int ind;
        for(int i=1;i<=n;i++)
        {
            if(dp[i][n]!=INT_MAX)
            {
                ind=i;
                break;
            }
        }
        if(t)
            cout<<endl;
        cout<<"Case "<<++t<<":"<<endl;
        cout<<"Minimum number of lectures: "<<ind<<endl;
        cout<<"Total dissatisfaction index: "<<dp[ind][n]<<endl;
    }
    return 0;
}