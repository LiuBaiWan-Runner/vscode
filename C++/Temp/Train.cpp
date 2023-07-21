#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin>>n>>m;
    int now = 1;
    stack<int> st;
    vector<string> ans;
    for(int i=0; i<n; i++){
        cin>>x;
        while(now <= x){
            st.push(now);
            now++;
            ans.push_back("push");
        }
        if(st.size() > m){
            cout<<"No"<<endl;
            return 0;
        }
        if(st.top() == x){
            st.pop();
            ans.push_back("pop");
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

