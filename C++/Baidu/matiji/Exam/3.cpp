#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int q=0;
    for(int i=1;i<=n;i++){
        int a=i, b=0, c=0;
        while(a!=0){
            b=a%10;
            a=a/10;
            c=c*10+b;
        }
        if(i%c==0){
            q++;
        }
    }
    cout << q <<endl;
    return 0;
}
