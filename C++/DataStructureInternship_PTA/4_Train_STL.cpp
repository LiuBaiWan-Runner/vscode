/*
 * @file    :4_Train_STL.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :Train_STL
 *          :栈：列车中转站后进先出
 *          :
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 2e6;
int n, m, x, t = 1;
stack<int> s; //初始化int类型的栈s
vector<string> a; //初始化string类型的容器a

void Push(int x);
bool Pop(int x);
void Display();

int main()
{
    cin >> n >> m;
    while(n--){
        cin >> x;
        Push(x);
        if(s.size() > m){
            cout<<"No"<<endl;
            return 0;
        }
        if(!Pop(x)){
            return 0;
        }
    }
    Display();
    return 0;
}

// 执行压入操作
void Push(int x){
    while(t <= x){ //将t从1开始压入
        s.push(t);
        t++;
        a.push_back("push");
    }
}

// 执行弹出操作，通过返回值控制无法实现的情况输出No 
bool Pop(int x){
    if(s.top() == x){
        s.pop();
        a.push_back("pop");
        return true;
    }else{
        cout<<"No"<<endl;
        return false;
    }
}

// 结果输出函数
void Display(){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<endl;
    }
}