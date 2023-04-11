  /*
  * @file    :9_1.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :前缀表达式求值（由后缀表达式求值修改来的）
  *          :<stack>库实现
  *          :WA
  */
#include<iostream>
#include<stack>
#include<cstring>
#include<iomanip>
using namespace std;
#define MAX 10000

int main() {
    string s[MAX];
    char temp;
    int m = 0;
    while((temp=cin.get())!='\n'){
        if(temp == ' '){
            m++;
            continue;
        }
        s[m] +=temp;
    }
    double num1, num2;
    stack<double>st;
    for(int i=m;i>=0;i--){
        char ch=s[i][0];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            num1=st.top();
            st.pop();
            num2=st.top();
            st.pop();
            if(ch=='+')st.push(num2+num1);
            if(ch=='-')st.push(num2-num1);
            if(ch=='*')st.push(num2*num1);
            if(ch=='/')st.push(num2/num1);
        }else{
            st.push(stof(s[i]));
        }
    }
    
    // cout<< setiosflags(ios::fixed) << setprecision(6) << st.top() << endl;
    printf("%.6f\n",st.top());
}