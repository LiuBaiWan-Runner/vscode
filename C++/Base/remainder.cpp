#include <iostream>

using namespace std;


int main()
{
    int a,b;
    for (int i = 0;; i++){
        cout<<"请输入被除数：";
        cin>>a;
        if(a==0)break;
        cout<<"请输入除数：";
        cin>>b;
        cout<<"余数为： "<<a%b<<endl;
    }
    return 0;
}
