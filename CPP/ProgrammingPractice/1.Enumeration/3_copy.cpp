/*
* @file    :3_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/h707981960/article/details/123673811
*          :
*          :
*/
#include <iostream>
using namespace std;
int arr[8][8]; //灯泡状态矩阵，8阶自有其意
int vis[8][8]; //开关状态矩阵，8阶自有其意

//判断在开关状态矩阵第一行的所有全排列种类中
//能够让灯泡状态矩阵最后一行灯恰好关闭
bool check()
{
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 7; j++)
            vis[i + 1][j] = (arr[i][j] + vis[i][j - 1] + vis[i][j] + vis[i][j + 1] + vis[i - 1][j]) % 2;
    //第一项是关灯，后面四项是为了抵消四周操作而增广为8阶是为了避免讨论在四角和边界的情况,

    //循环下来开关状态矩阵枚举完毕,下面进行判定最后一行是否恰能满足
    for (int i = 1; i < 7; i++)
    {
        if ((vis[5][i - 1] + vis[5][i] + vis[5][i + 1] + vis[4][i]) % 2 != arr[5][i])
            return false;
    }
    return true;
}


//对开关状态矩阵第一个"控制行"进行全排列
void sol()
{
    for (int i = 1; i < 7; i++)
        vis[1][i] = 0; //开关状态矩阵第一个"控制行"均赋0
    while (!check())   //进行奇偶全排列，奇代表1，偶代表0
    {                  //后续对2求余即可
        vis[1][1]++;
        int tag = 1;
        while (vis[1][tag] > 1)
        {
            vis[1][tag] = 0;
            tag++;
            vis[1][tag]++;
        }
    }
}

int main()
{
    // int round;
    // cin >> round;
    // for (int k = 0; k< round; k++)
    // {
    //   cout<<"PUZZLE #"<<k+1<<endl;
    for (int i = 0; i < 6; i++)
    {
        vis[i][0] = vis[i][7] = 0; // vis[:,0]=vis[:,7]=0;
    }
    for (int i = 0; i < 7; i++)
    {
        vis[0][i] = 0; // vis[0,:]=0;
    }
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            cin >> arr[i][j]; //输入灯泡状态矩阵，且用下标就是代表序数，从1开始
        }
    }
    sol();
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    // }
    return 0;
}
