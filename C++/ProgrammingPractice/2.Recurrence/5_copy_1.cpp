/*
* @file    :5_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :24点游戏
*          :https://blog.csdn.net/qq_42403733/article/details/82925006
*          :
*/
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;

const double LING=1E-6;
const int COUNT=4;
const int VOLUE= 24;
double num[COUNT];
string E[COUNT];

bool Game(int n)
{
    if (n==1) 
	{
        if (fabs(num[0]-VOLUE)<LING) 
		{
			cout<<E[0]<<"="<<VOLUE<< endl;

			ofstream mycout("TopList.txt");  //将结果写入文件中
			mycout<<E[0]<<"="<<VOLUE<<endl;
			mycout.close();
            return true;    //判断是否有解
        } 
		else 
		{
            return false;
        }
    }

    for (int i=0;i<n;i++) 
	{
        for (int j=i+1;j<n;j++) 
		{
            double a, b;
            string A, B;
            a=num[i];
            b=num[j];
            num[j]=num[n-1];  //递归之后，n比以前小一位，不停向前赋值

            A=E[i];
            B=E[j];
            E[j]=E[n - 1];   //递归之后，n比以前小一位，不停向前赋值

            E[i] = '(' +A+ '+' +B+ ')';  //判断加法能否算出
            num[i] = a + b;
            if ( Game(n - 1) ) return true;
            
            E[i] = '(' +A+ '-' +B+ ')';  //判断减法能否算出(需要分顺序)
            num[i] = a - b;
            if ( Game(n - 1) ) return true;
            
            E[i] = '(' +A+ '-' +B+ ')';  
            num[i] = b - a;
            if ( Game(n - 1) ) return true;
                        

            E[i] = '(' +A+ '*' +B+ ')';  //判断乘法能否算出
            num[i] = a * b;
            if ( Game(n - 1) ) return true;

            if (b != 0) {
                E[i] = '(' +A+ '/' +B+ ')';  //判断除法能否算出(需要分顺序)
                num[i] = a / b;
                if ( Game(n - 1) ) return true;
            } 
            if (a != 0) {
                E[i] = '(' +A+ '/' +B+ ')';  
                num[i] = b / a;
                if ( Game(n - 1) ) return true;
            }
            num[i] = a;  //如果上面几种可能都失败了,把原来的赋值撤消,以无干扰的正确的进入到下一次for循环队列中。
            num[j] = b;
            E[i] = A;
            E[j] = B;
        }
    }
    return false;
}

/*主函数*/
int main(int argc, char* argv[])
{
	cout<<"*****************欢迎来到24点游戏****************"<<endl;
	cout<<"请输入4个数（1—13）"<<endl;
    for (int i=0;i<COUNT;i++) 
	{
        char game[20];
        int  x;
        cin>>x;    //读入数据
        num[i]=x;
        itoa(x,game,10);  //itoa()函数把第一个数值传送到第二个(字符串)中去，第三个参数以int型存放。
        E[i]=game;
    }
    if (Game(COUNT)) 
	{
        cout<< "成功！" << endl;
    } 
	else 
	{
        cout<< "没有结果..." << endl;
    }        
    return 0;
}
