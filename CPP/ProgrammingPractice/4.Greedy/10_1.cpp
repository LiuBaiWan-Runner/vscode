https://blog.csdn.net/C_Dreamy/article/details/104738151

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int idata=1e3+5;
 
int i,j,k;
int judge,flag;
//vector<int> step(idata);
int cs[2][idata];
int n,m,t;
int maxx=0,minn=inf;
ll cnt,len;
 
bool cmp(int a,int b)
{   return a>b;     }
 
int solve(int c[],int s[])
{
    int ans=0;
    int cleft=1,sleft=1;
    int cright=n,sright=n;
 
    while(sleft<=sright)
    {
    if(s[sleft]>c[cleft])
    {
        ans+=3;
        sleft++;
        cleft++;
    }
    else if(s[sleft]<c[cleft])
    {
        ans+=1;
        cleft++;
        sright--;
    }
    else
    {
        if(s[sright]>c[cright])
        {
            ans+=3;
            sright--;
            cright--;
        }
        else
        {
            if(s[sright]==c[cleft])
            {
                cleft++;
                sright--;
                ans+=2;
            }
            else
            {
                cleft++;
                sright--;
                ans+=1;
            }
        }
    }
    }
    return ans;
}
 
int main()
{
    while(cin>>n&&n)
    {
        memset(cs,0,sizeof(cs));
        for(i=1;i<=n;i++)
            cin>>cs[0][i];
        for(i=1;i<=n;i++)
            cin>>cs[1][i];
 
        sort(cs[0]+1,cs[0]+1+n,cmp);
        sort(cs[1]+1,cs[1]+1+n,cmp);
 
        //solve(cs[0],cs[1]);
        cout<<solve(cs[0],cs[1])<<' '<<4*n-solve(cs[1],cs[0])<<endl;
    }
 
 
    return 0;
}