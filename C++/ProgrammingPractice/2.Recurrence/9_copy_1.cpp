  /*
  * @file    :9_copy_1.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :后缀表达式求值
  *          :https://www.cnblogs.com/xxxsans/p/13917638.html
  *          :
  */
#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int main() {
    string s;
    cin>>s;
    stack<int>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            int num1=st.top();
            st.pop();
            int num2=st.top();
            st.pop();
            if(s[i]=='+')st.push(num2+num1);
            if(s[i]=='-')st.push(num2-num1);
            if(s[i]=='*')st.push(num2*num1);
            if(s[i]=='/')st.push(num2/num1);
        }else{
            char ch=s[i];
            string s2;
            char s1[2]={ch,0};
            s2=s1;
            st.push(stoi(s2));
        }
    }
    
    cout<<st.top();

}