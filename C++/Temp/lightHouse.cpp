#include<iostream>
using namespace std;
int main()
{
    int n,ans = 0;
    cin>>n;
    int a[n+10][2];
    for(int i=0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((a[j][0] - a[i][0]) * (a[j][1] - a[i][1]) > 0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
