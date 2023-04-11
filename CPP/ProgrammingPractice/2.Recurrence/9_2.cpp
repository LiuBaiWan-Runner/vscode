  /*
  * @file    :9_2.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-08
  * @brief   :前缀表达式求值（由后缀表达式求值修改来的）
  *          :数组实现堆栈
  *          :WA
  */

#include<iostream>
// #include<stack>
#include<cstring>
#include<iomanip>
using namespace std;
#define MAX 10000
double stack[10001];
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
    int i=m,top=0;
	while(i>=0){
        char ch=s[i][0];
		switch(ch)
		{
			case '+':
                top--;
				stack[top]+=stack[top+1];
                break;
			case '-':
				top--;
				stack[top]-=stack[top+1];
                break;
			case '*':
				top--;
				stack[top]*=stack[top+1];
                break;
			case '/':
				top--;
				stack[top]/=stack[top+1];
                break;
			default:
                top++;
				stack[top]=stod(s[i]);
				break;
		}
		i--;
        // cout << stack[top] << endl;
	}
    
    // cout<< setiosflags(ios::fixed) << setprecision(6) << st.top() << endl;
    printf("%.6f\n",stack[top]);
}