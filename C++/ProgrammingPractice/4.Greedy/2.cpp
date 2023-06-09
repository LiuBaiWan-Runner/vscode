https://blog.csdn.net/qq_42995099/article/details/82085050

#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[1005];
    while(scanf("%d",&n)!=EOF) //无限输入
    {
        int max=-1,sum=0;//max储存用时最长的那节电池，sum存储其他电池的用时总和
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i]; //求和
            if(max<a[i]) max=a[i]; //找出用时最长的那节电池
        }
        if((sum-max)<max)
        /*第一种情况:如果所有除了用时最长的那节电池外的其他所有电池用时
    总和都不能用完用时用时最长的那节电池的话，说明总时间为除了用时最长的
那节电池外的其他电池的用时总和，可能有点绕，其实很简单，再理一理^_^*/
        {
            printf("%.1f\n",(sum-max)*1.0); //保留一位小数输出
        }
        else/*第二种情况：就是除了用时最长的那节电池外的其
他所有电池用时总和能怼完用时最长的那节电池，说明答案是用时最
长的那节电池的用时加剩下的时间除以2，相信读到这里，大家大概
也知道上面我为什么说是两节电池怼半个小时了*/
        {
            printf("%.1f\n",(sum-max-max)*1.0/2+max);//输出对应的结果
        }
    }
    return 0;//完美结束
} 
/*贪心策略并不难，但是要想到第二种情况可能就是能力问题
了（因为第一次听课时，我也在坐飞机），在多走一走，虽然
代码量短，但要理解透，还是不那么简单，再多多整理^_^*/