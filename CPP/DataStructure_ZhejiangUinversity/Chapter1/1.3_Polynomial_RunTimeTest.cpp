#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

clock_t start,stop;
double ticks,duration;

#define MAXN 100
#define MAXK 1e7

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

void output(){
    ticks=(double)(stop-start);
    duration=ticks/CLK_TCK;
    cout<<ticks<<endl;
    cout<<duration<<endl;
    return;
}

int main() {

    double s;
    double coeff[MAXN];
    
    start=clock();
    for(int i=0;i<MAXK;i++){
        
        for(int i=0;i<MAXN;i++){
            coeff[i]=(double)i;
        }
        method_1(MAXN-1,coeff,1);
        method_2(MAXN-1,coeff,1);
    }
    stop=clock();
    output();

    return 0;
}

