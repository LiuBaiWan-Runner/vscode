/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/HT24k/article/details/106991974
 *          :
 *          :
 */
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,x,flag,a[101],book[101];
void dfs(int deep,int len,int dex)
{
 int i;
 if(len==0)
 {
  i=1;
  while(book[i])
  i++;
  book[i]=1;
  dfs(deep+1,len+a[i],i+1);
  book[i]=0;
  return;    //及时返回，避免不不必要的搜索
 }
 if(len==x)
 {
  if(deep==n)
  {
   flag=1;
  }
  else {
   dfs(deep,0,1);
  }
  return;
 }
 for(i=dex;i<=n;i++)
 {
  if(book[i])
  continue;
  if(len+a[i]<=x)
  {
   if(a[i]==a[i-1]&&book[i-1]==0)
   continue;
   book[i]=1;
   dfs(deep+1,len+a[i],i+1);
   book[i]=0;
   if(flag)
   return;
   if(len+a[i]==x)
   return;
  }
 }
 return;
}
bool cmp(int a,int b)
{return a>b;}
int main()
{
 int i,sum;
 while(cin>>n||n)
 {
  sum=0;
  for(i=1;i<=n;i++)
  {
   cin>>a[i];
   sum+=a[i];
  }
  sort(a+1,a+n+1,cmp);
  for(i=a[1];i<=sum;i++)
  {
   if(sum%i)
   continue;
   x=i;
   memset(book,0,sizeof(book));
   flag=0;
   dfs(0,0,1);
   if(flag)
   {
    cout<<i<<endl;
    break;
   }
  }
 }
 return 0;
}