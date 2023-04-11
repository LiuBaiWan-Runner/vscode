https://blog.csdn.net/chimchim04/article/details/81041689

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1005],b[1005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        int i=0,j=0,x=n-1,y=n-1,k=0,sum=0;
        while(1)
        {
            if(k==n) break;
            if(a[i]>b[j]){i++;j++;sum++;k++;}
            else if(a[i]<b[j]){x--;j++;sum--;k++;}
            else if(a[i]==b[j])
            {
                if(a[x]>b[y]){x--;y--;sum++;k++;}
                else
                {
                    if(a[x]==b[j]) {x--;j++;k++;}
                    else if(a[x]<b[j]){x--;j++;sum--;k++;}
                }
            }
        }
        printf("%d\n",sum*200);
    }
    return 0;
}