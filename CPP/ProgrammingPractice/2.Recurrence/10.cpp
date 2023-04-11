  /*
  * @file    :10.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-09
  * @brief   :左右括号匹配
  *          :
  *          :AC
  */
#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int main() {
    char b[101];
    string str;
    while(getline(cin,str)){
        int l = str.size();
		stack<int>st;
        st.push(0);
        for(int i = 0; i<l; i++){
            if(str[i] == '('){
                st.push(i+1);
                b[i] = '$';
            }
            else if(str[i] == ')'){
                b[i] = '?';
                if(st.top() != 0){
                    b[st.top()-1] = ' ';
                    b[i] = ' ';
                    st.pop();
                }
            }
            else{
                b[i] = ' ';
            }
        }
        cout << str << endl;
        for(int i = 0; i<l; i++){
            cout << b[i];
        }
        cout << endl;
    }
	return 0;
}