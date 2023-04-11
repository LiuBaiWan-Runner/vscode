/*
* @file    :4_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/wyi06/article/details/55049807
*          :
*          :
*/
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    string inp;
    int ndir = 1; //标志缩进 ，也说明了目录的级数 
    priority_queue <string,vector<string>, greater<string> > q[1005];
    int mark = 1; //标志是否输出ROOT 
    int ca = 1; //标志第几次测试 
 
    while(true)
    {
        cin >> inp;
        if(inp[0] == '#') break;
        if(mark)
        {
            cout <<"DATA SET "<< ca << ":" <<endl;
            cout << "ROOT" << endl;
            mark = 0;
        }
        if(inp[0] == 'd') //遇见目录直接输出 
        {
            for(int i = 0; i < ndir; i++)
                cout << "|     ";
            cout << inp << endl;
            ndir++;
        }
        else if(inp[0] == 'f') //遇到文件放入队列，并排序 
        {
            q[ndir].push(inp);
        }
        else if(inp[0] == ']' || inp[0] == '*')  
        {
            while(!q[ndir].empty())
            {
                for(int i = 0; i < ndir - 1; i++)
                    cout << "|     ";
                cout << q[ndir].top() << endl;
                q[ndir].pop();
            }
            ndir--;
        }
        if(inp[0] == '*')
        {
            mark = 1;
            ndir = 1;
            ca++;
            cout <<endl;
        }
    }
    return 0;
}