#include<iostream>
using namespace std;
#define N 500000
int main()
{
    int n,m,a,b;
    int nums[N+10];
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    while(m--){
        cin>>a>>b;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= a && nums[i] <= b){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
