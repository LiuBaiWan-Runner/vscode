https://www.cnblogs.com/MisdomTianYa/p/6581827.html

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct node
{
 double xL,xR;
}p[1010];
int cmp(const void*a,const void*b)
{
 return ((node*)a)->xL>((node*)b)->xL?1:-1;
}
int main()
{
    int n,d,cnt=1;
 while(cin>>n>>d&&(n||d))
 {
  int flag=1;
  if(d<=0)
   flag=0;
  for(int i=0;i<n;i++)
  {
   int x,y;
   cin>>x>>y;
   if(y>d)
      flag=0;
   double t=sqrt(1.0*(d*d-y*y));
   p[i].xL=x-t;
   p[i].xR=x+t;
  }
  if(flag)
  {
   qsort(p,n,sizeof(p[0]),cmp);
   int sum=1;
   double high=p[0].xR;
   for(int i=1;i<n;i++)
   {
    if(p[i].xL>high)
    {
     sum++;
     high=p[i].xR;
    }
    else
      high=high<p[i].xR?high:p[i].xR;
   }
   cout<<"Case "<<cnt++<<": "<<sum<<endl;
  }
  else
    cout<<"Case "<<cnt++<<": -1"<<endl;
 }
 return 0;
}