/*
 * @file    :4_csdn.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2213质数率
 *          :CSDN:https://blog.csdn.net/m0_54754302/article/details/128126714
 *          :
 */

#include<bits/stdc++.h> 

using namespace std;

int prime[100000000],cnt,n;
bool vis[100000000];

void init(){
    for(int i=2;i<=n;++i){
        if(!vis[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt;++j){
            if(prime[j]*i>n) break;
            vis[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
}
int main( )
{
    cin>>n;
    init();
    cout<<fixed<<setprecision(3)<<(1.0*cnt/n);
    return 0;
}
