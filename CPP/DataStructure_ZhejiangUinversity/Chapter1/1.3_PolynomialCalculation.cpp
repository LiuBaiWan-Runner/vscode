#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

double method_1(int n,double coeff[],double x){//直接计算方法
    double s=coeff[0];
    for(int i=1;i<=n;i++){
        s+=(coeff[i]*pow(x,i));
    }
    return s;
}

double method_2(int n,double coeff[],double x){//秦九韶计算方法
    double s=coeff[n];
    for (int i = n; i >0; i--){
        s=coeff[i-1]+x*s;
    }
    return s;
    
}

int main()
{
    double s;
    double coeff[MAXN];
    for(int i=0;i<MAXN;i++){
        coeff[i]=(double)i;
    }
    cout<<method_1(MAXN-1,coeff,1)<<endl;
    cout<<method_2(MAXN-1,coeff,1)<<endl;
    return 0;
}
