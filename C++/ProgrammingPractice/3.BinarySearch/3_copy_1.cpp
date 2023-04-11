/*
* @file    :3_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :4 Values whose Sum is 0(二分+排序)
*          :https://www.cnblogs.com/lisijie/p/7289457.html
*          :
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4005;
int a[N],b[N],c[N],d[N];
int ab[N*N],cd[N*N];
int main()
{
   int n,total=0,i,j;
   while (cin>>n)
   {
         for (i=0;i<n;i++)
           cin>>a[i]>>b[i]>>c[i]>>d[i];
           int num1=0,num2=0;
         for (i=0;i<n;i++)
            for (j=0;j<n;j++)
           {
                ab[num1++]=a[i]+b[j];
                cd[num2++]=-(c[i]+d[j]);
           }
          sort (cd,cd+num2);
         for (i=0;i<num1;i++)
           {
              int mid,up=num2-1,low=0;
             while (low<=up)
             {
                mid=low+(up-low)/2;
               if (ab[i]==cd[mid])
                {
                  total++;
                    for (j=mid+1;j<=up;j++)
                  {

                       if (ab[i]==cd[j])
                          total++;
                       else
                           break;
                  }
                  for (j=mid-1;j>=low;j--)
                  {
                       if (ab[i]==cd[j])
                         total++;
                       else
                         break;
                  }


                  break;
              }
              else
              {
                  if (ab[i]>cd[mid])
                    low=mid+1;
                  else
                    up=mid-1;
              }
        }
    }
      cout << total << endl;
   }

        return 0;
}