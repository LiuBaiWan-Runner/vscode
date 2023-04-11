#include<iostream> 

using namespace std;
int func(int a,int b);
int c,d;
int main( )
{
    int a,b;
    cin >> a >> b >> c >> d ;
    cout << func(a,b) << endl;
    return 0;
}

int func(int a,int b){
    if(a == 1){
        return (c*b+d)%10;
    }
    else {
        return func(a-1,func(a-1,b))%10;
    }
}