// https://blog.csdn.net/llovebeauty/article/details/124516707
// 这里标记这个人有没有被别人接触过
// 如果没有被接触，那么他就是传染源，因为给出的所有人都被传染
// 即没有孤立结点
#include<bits/stdc++.h>
using namespace std;
vector<int> v[10010],jg,zj;//存储图、结果序列、遍历时的临时序列
void dfs(int x){
    for(int i=0;i<v[x].size();i++){
    	zj.push_back(v[x][i]);
        dfs(v[x][i]);
        zj.pop_back();
    }
    if(zj.size()>jg.size())jg=zj;//如果找到的传染链长就记下来
}
int main()
{
    int n,bj[10010];//bj数组用来判断是否出现过
    cin >> n;
    for (int i = 0; i < n;i++){//存储图
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            v[i].push_back(x);
            bj[x] = 1;
        }
    }
    int BT=0;
    for (int i = 0; i < n;i++){//找到传染源
        if(!bj[i]){
            BT = i;
            break;
        }
    }
    dfs(BT);
    cout << jg.size()+1<<endl<<BT;
    for(auto k:jg){
    	cout<<" "<<k;
	}
    return 0;
}