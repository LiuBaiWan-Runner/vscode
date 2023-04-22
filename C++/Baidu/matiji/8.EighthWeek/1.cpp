/*
 * @file    :1.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-21
 * @brief   :MT2113栈的min
 *          :
 *          :AC
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> stackValue;
stack<int> stackMin;

void push(int x){
    stackValue.push(x);
    if(stackMin.empty() || stackMin.top() >= x){
        stackMin.push(x);
    }
}

void pop(){
    if(stackMin.top() == stackValue.top()){
        stackMin.pop();
    }
    stackValue.pop();
}

int top(){
    return stackValue.top();
}

int getMin(){
    return stackMin.top();
}

int main()
{
    int n;
    cin >> n;
    int t;
    while(n--){
        cin >> t;
        switch (t)
        {
        case 1:
            int x;
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            // cout << endl;
            cout << top() << endl;
            break;
        case 4:
            // cout << endl;
            cout << getMin() << endl;
            break;
        }
    }
    return 0;
}
