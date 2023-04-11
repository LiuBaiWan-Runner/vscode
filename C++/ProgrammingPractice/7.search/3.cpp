/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-11
 * @brief   :https://blog.csdn.net/WaveBridge/article/details/74959813
 *          :
 *          :
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int N,M;              //体积为N，层数为M 
int minS = 1 << 30;   //最小外表面积
int s;                //当前外表面积 

int tempS[21]={0};        //制作i层的最小表面积
int tempMinV[21]={0};     //制作i层的最小体积
int tempMaxV;             //制作i层的最大体积(需要根据上一层的半径和高计算，不能初始化) 

void dfs(int v, int n, int r, int h)
{
    //边界条件 还需要搭0层 
    if(n == 0)
    {
        if(v != 0)
            return ;
        else
        {
            if(minS > s)
                minS = s;
            return ;    
        } 
    } 

    if(v <= 0)        //因为n是每次-1，所以不用判断小于0的状态 
        return ;

    //最优性剪枝
    //之后的面积一定不会更小 
    if(s + tempS[n] >= minS)
        return ;

    //可行性剪枝
    if(tempMinV[n] > v)
        return ;


    //循环所有的能到达的结点，也就是状态
    for(int rr = r; rr >= n; rr--)  //因为还有n层，所以这里半径最小只能是n  
    {
        for(int hh = h; hh >= n; hh--)
        {
            //如果是第一层 那就先s=底面积也就是外表面积的上面的和  
            if(n == M)
                s = rr*rr;

            tempMaxV = 0;
            //算出最大能得到多大的体积
            for(int i = 1; i<= n-1; i++)
            {
                tempMaxV += (rr-i)*(rr-i)*(hh-i);
            }

            if(v-rr*rr*hh > tempMaxV)
                continue;

            s += 2*rr*hh;
            dfs(v-rr*rr*hh,n-1,rr-1,hh-1);
            s -= 2*rr*hh;
        } 
    } 
}

int main()
{
    scanf("%d %d",&N,&M);
    s = 0;
    //最大是体积为10000 那么我们先估计最大半径和最大高度 
    //r = 100,h = 10000; 

    //初始化，便于剪枝
    for(int i = 1; i <= 20; i ++)
    {
        for(int j = 1; j <= i ;j ++)
        {
            tempMinV[i] += pow(j,3);    
            tempS[i] += 2*pow(j,2);
        }   
        //最大体积只能知道上一层的半径和高才能算 
    } 


    dfs(N,M,100,10000);

    if(minS == 1 << 30)
        printf("0");

    else printf("%d",minS);  

    return 0;   
} 