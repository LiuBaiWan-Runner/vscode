  /*
  * @file    :8_copy_2.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :Factorization
  *          :因式分解
  *          :
  */

#include<bits/stdc++.h>
using namespace std;
int sum;
void f(int x,int y)
{
    for(int i=x;i<y;i++)
    {
        if(y%i==0&&i<=y/i)
        {
            sum++;
            f(i,y/i);
        }
        if(i>y/i)
            return;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        sum=1;
        int n;
        cin>>n;
        f(2,n);
        cout<<sum<<endl;
    }
    return 0;
}