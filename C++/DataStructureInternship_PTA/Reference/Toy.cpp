/*
初态： 1 2 3 4 5 6 7 8
A变换：8 7 6 5 4 3 2 1
B变换：5 8 7 6 3 2 1 4
C变换：5 1 8 6 3 7 2 4
*/

#include<bits/stdc++.h>
using namespace std;

//存放阶乘
int jie[9] = {1,1,2,6,24,120,720,5040,40320};

int Cantor(int adr[])//康托函数
{
    int sou = 0,cnt;
    for(int i = 0; i < 7; i++)
    {
        cnt = 0;
        for(int j = i + 1; j < 8; j++)
        {
            if(adr[j] < adr[i])
            {
                cnt++;//逆序数
            }
        }
        sou += cnt * jie[7 - i];//阶乘求和
    }
    return sou;
}
void nCantor(int x,int adr[])//逆康托函数
{
    int s[8],t,j,l;
    memset(&s,0,sizeof(s));
    for(int i = 0; i < 8; i++)
    {
        t = x / jie[7 - i];
        x -= t * jie[7 - i];
        for(j = 0,l = 0; l <= t; j++)
        {
            if(s[j] == 0)
            {
                l++;
            }
        }
        j--;
        s[j] = 1;
        adr[i] = j + 1;
    }
}
//定义三种变换
int A(int a)//交换行
{
    int tmp[8],s[8];
    nCantor(a,tmp);
    s[0] = tmp[4];
    s[1] = tmp[5];
    s[2] = tmp[6];
    s[3] = tmp[7];
    s[4] = tmp[0];
    s[5] = tmp[1];
    s[6] = tmp[2];
    s[7] = tmp[3];
    return Cantor(s);
}
int B(int b)//循环右移
{
    int tmp[8], s[8];
    nCantor(b,tmp);
    s[0] = tmp[3];
    s[1] = tmp[0];
    s[2] = tmp[1];
    s[3] = tmp[2];
    s[4] = tmp[7];
    s[5] = tmp[4];
    s[6] = tmp[5];
    s[7] = tmp[6];
    return Cantor(s);

}
int C(int c)//中心顺时针旋转
{
    int tmp[8],s[8];
    nCantor(c, tmp);
    s[0] = tmp[0];
    s[1] = tmp[5];
    s[2] = tmp[1];
    s[3] = tmp[3];
    s[4] = tmp[4];
    s[5] = tmp[6];
    s[6] = tmp[2];
    s[7] = tmp[7];
    return Cantor(s);

}

struct node
{
    string pum;
    int folat;//康托数
    node(string a = "",int b = -1):pum(a),folat(b) {}
};

int main()
{
    queue <node> q;//广度优先搜索队列
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int mban[8],sum,cnt = 0;
        int chu[] = {1, 2, 3, 4, 8, 7, 6, 5}; //初始状态
        bool flog = true,hashcode[50000] = {false};
        for(int i = 0; i < 4; i++)
        {
            scanf("%d",&mban[i]);
        }
        for(int i = 7; i > 3; i--)
        {
            scanf("%d",&mban[i]);
        }
        sum = Cantor(mban);//计算康托数
        node a("",Cantor(chu));
        q.push(a);
        while(flog)
        {
            cnt++;
            int m = q.size();
            for (int i = 0; i < m && flog; i++)
            {
                node tmp = q.front();
                q.pop();
                if (tmp.folat == sum)
                {
                    flog = false;
                    string res = tmp.pum;
                    int le = res.size(), hang = le / 60; // 计算输出行数
                    printf("%d\n",cnt - 1);
                    for (int k = 0; k < hang + 1; k++) // 每行60个字符
                    {
                        for (int j = 0; j < 60 && le > 0; j++)
                        {
                            le--;
                        }
                    }
                }
                if(flog)
                {
                    int a1 = A(tmp.folat), a2 = B(tmp.folat), a3 = C(tmp.folat);
                    // 判断三种操作后产生的情况是否出现过，没有则入队，并记录相应的操作步骤
                    if (!hashcode[a1])
                    {
                        hashcode[a1] = true;
                        string f = tmp.pum + "A";
                        node x(f, a1);
                        q.push(x);
                    }
                    if (!hashcode[a2])
                    {
                        hashcode[a2] = true;
                        string f = tmp.pum + "B";
                        node x(f, a2);
                        q.push(x);
                    }
                    if (!hashcode[a3])
                    {
                        hashcode[a3] = true;
                        string f = tmp.pum + "C";
                        node x(f, a3);
                        q.push(x);
                    }
                }
            }

        }
    }
    return 0;
}
