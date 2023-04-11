#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j,num=0,r=0;
    cin>>n>>m;
    int a[10],b[10],c[20];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
              c[num++]=a[i];
              r++;
            }
        }
    if(r==0)
        cout<<"NULL";
    else
    {
      for(i=0;i<num-1;i++)
      cout<<c[i]<<' ';
      cout<<c[i];
    }
      return 0;
}