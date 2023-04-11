#include<iostream>
#include<string>
using namespace std;

int m ,n;
int x, y, k;

struct ZhangaiNode {
    int a, b;
}Node[1000];

bool Judge(int x,int y){

    if(x<1||x>n||y<1||y>m)
        return false;

    for(int i=1;i<=k;i++){
        if(x==Node[i].a&&y==Node[i].b)
            return false;
    }
    return true;
}

int main() 
{ 
    // int m ,n;
    // int x, y, k;
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    for(int i=1;i<=k;i++){
        int a, b;
        cin >> a >> b;
        Node[i].a = a;
        Node[i].b = b;
    }

    string s;
    cin >> s;
    int Xn = x, Yn = y;

    for(int i=0;i<s.length();i++){
        if(s[i] == 'L'){
            while(Judge(Xn,Yn)){
                Yn--;
            }
            Yn++;
            // cout << Xn << " " << Yn << endl;
        }
        if(s[i] == 'R'){
            while(Judge(Xn,Yn)){
                Yn++;
            }
            Yn--;
            // cout << Xn << " " << Yn << endl;
        }
        if(s[i] == 'U'){
            while(Judge(Xn,Yn)){
                Xn--;
            }
            Xn++;
            // cout << Xn << " " << Yn << endl;
        }
        if(s[i] == 'D'){
            while(Judge(Xn,Yn)){
                Xn++;
            }
            Xn--;
            // cout << Xn << " " << Yn << endl;
        }
    }
    cout << Xn << " " << Yn << endl;
    return 0; 
}