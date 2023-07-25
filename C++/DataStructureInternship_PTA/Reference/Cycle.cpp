// 输入两个字符串 str1 和 str2，定义一个新字符串 str = str1+str1
// 若 str2 是 str 的子串，则 str1 可以通过若干次循环移位得到 str2，否则则不能
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string str1,str2;
        cin>>str1>>str2;
        string str = str1+str1;
        if(str.find(str2) != -1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
