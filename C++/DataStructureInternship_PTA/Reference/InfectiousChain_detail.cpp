// https://blog.csdn.net/weixin_46050495/article/details/124134007
// 这里对图中每一个结点都进行了深搜
#include<bits/stdc++.h>
using namespace std;

vector<int> v[10010];//记录人员接触信息

int step[10010];//step[i]表示从人员i开始可以传染的最长的链的长度
int nxt[10010];//最终的nxt[i]将表示最长最早的传染链上人员i传染的下一个人员
int ans=0;//最终的传染链长度

//获取从人员index开始的最长最早的传染链长度
int dfs(int index)
{
    //人员index没有接触其他人时，从它开始的传染链则为他自己，长度即为1
    if(v[index].size()==0)
        return 1;
        
    int steps=0;//将作为返回值，表示从index开始的最早最长的传染链长度
    for(int i=0;i<v[index].size();i++)//遍历人员index接触过的人
    {
        //v[index][i]指人员index接触的第i个人的编号，假设它为k
        int k=v[index][i];
        //step[k]即表示从人员k开始的最早最长的传染链长度
        //如果这个长度加上它走到k这一步大于现在记录的最长的长度steps，则进行更新，step[k]等于0时前面的大于情况也满足，需要排除
        if(step[k]+1>steps&&step[k]!=0)
         {
            //从index开始走到人员k只需要走1步，
            //从人员k开始的最长的传染链长度为step[k],
            //所以从index开始最长的传染链长度就为step[k]+1
            steps=step[k]+1;
            nxt[index]=k;//目前找到的最长最早传染链中index接触的下一个人为k
        }
        else if(step[k]==0)//如果还不知道从k开始的传染链长度
        {
            //获取从k开始的最长的传染链长度dfs(k)
            //然后加上从index走到k这个位置的1步
            int temp=dfs(k)+1;
            if(temp>steps)//和上一个if的判断方法一致
            {
                steps=temp;
                nxt[index]=k;
            }
        }
    }
    step[index]=steps;//记录从index开始最早最长的传染链的长度
    return steps;
}
int main()
{
    int n;
    cin>>n;//总人数
    memset(v,0,sizeof(v));
    memset(step,0,sizeof(step));
    memset(nxt,0,sizeof(nxt));
    for(int i=0;i<n;i++)//存储所有的传染信息
    {
        int k;
        cin>>k;//人员i接触的人数
        for(int j=0;j<k;j++)//把接触到的每个人都存入动态数组
        {
            int t;
            cin>>t;
            v[i].push_back(t);
        }
    }
    int index=0;
    for(int i=0;i<n;i++)//遍历每一条人员接触信息
    {
        int temp=dfs(i);//从人员i开始的最长的那条传染链的长度
        //传染链长度大于上一次记录的结果是记录该条链的起始点并更新最大长度
        if(temp>ans)
        {
            index=i;//起始点
            ans=temp;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans-1;i++)
    {
        cout<<index<<" ";
        index=nxt[index];
    }
    cout<<index;
}
