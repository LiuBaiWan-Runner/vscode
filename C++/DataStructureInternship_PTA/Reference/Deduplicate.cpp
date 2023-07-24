#include<bits/stdc++.h>
using namespace std;
#define N 600000

//使vector容器实现查找的函数
bool search(vector<string>& vec,string target){
    vector<string>::iterator it;
    it = find(vec.begin(), vec.end(), target);
    if(it != vec.end()){
        return true;
    }
    return false;
}

int main()
{
    int n;
    unordered_set<string> set1;  //存储不重复元素
    vector<string> vec;  //存储重复元素
    vector<string> ans;  //存储第一次重复的元素
    cin>>n;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        if(set1.count(str) && !search(vec,str)){  //重复且第一次重复
            ans.push_back(str);
        }
        if(set1.count(str)){  //重复
            vec.push_back(str);
        }
        set1.insert(str);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
