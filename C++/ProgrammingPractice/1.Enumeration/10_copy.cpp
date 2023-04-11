/*
* @file    :10_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/wangjingwan/article/details/119670090
*          :
*          :
*/
#include<iostream>
using namespace std;
int x[1050][1050]= {0};
int main() {
    int d,n;
    cin>>d>>n;
    int maxn=0;
    for(int i=0; i<n; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=0; j<1025; j++) {
            for(int k=0; k<1025; k++) {
                int shang=j-d,xia=j+d,zuo=k-d,you=k+d;
                if(a>=shang&&a<=xia&&b>=zuo&&b<=you) {
                x[j][k]+=c;
                if(x[j][k]>maxn) maxn=x[j][k];
                }
            }
        }
    }
    int cnt=0;
    for(int i=0; i<1025; i++) {
        for(int j=0; j<1025; j++)
            if(x[i][j]==maxn) cnt++;
    }
    cout<<cnt<<" "<<maxn;
    return 0;
}
 