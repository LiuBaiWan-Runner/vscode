/*
* @file    :6.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :2373:Dividing the Path（动态规划）
*          :https://www.cnblogs.com/aiqinger/p/12597450.html
*          :
*/
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;
const int MAXL=1000010;
const int MAXN=1010;
int F[MAXL],cows[MAXL],cowVary[MAXL];
int N,L,A,B;
struct Fx {
    int x,F;
    bool operator < (const Fx &a)const {
        return F>a.F;
    }
    Fx(int xx=0,int ff=0):x(xx),F(ff) {
    }

};
priority_queue <Fx> q;
int main() {
    cin>>N>>L>>A>>B;
    A<<=1;B<<=1;
    memset(cowVary,0,sizeof(cowVary));
    for(int i=0; i<N; i++) {
        int s,e;
        cin>>s>>e;
        ++cowVary[s+1];
        --cowVary[e];
    }
    int inCows=0;
    for(int i=0; i<=L; i++) {
        F[i]=INF;
        inCows+=cowVary[i];
        cows[i]=inCows;
    }
    for(int i=A; i<=B; i+=2) {
        if(!cows[i]) {
            F[i]=1;
            if(i<=B+2-A)q.push(Fx(i,1));
        }
    }
    for(int i=B+2; i<=L; i+=2) {
        if(!cows[i]) {
            Fx fx;
            while(!q.empty()) {
                fx=q.top();
                if(fx.x<i-B) {
                    q.pop();
                } else {
                    break;
                }

            }
            if(!q.empty())F[i]=fx.F+1;
        }
        if(F[i-A+2]!=INF) {
            q.push(Fx(i-A+2,F[i-A+2]));
        }
    }
    if(F[L]==INF)cout<<-1<<endl;
    else cout<<F[L]<<endl;
    return 0;
}