https://blog.csdn.net/WANG_ZIYE/article/details/105623231

#include<bits/stdc++.h>
using namespace std;
map<string,bool> mat;//使用map能更快捷完成本题 
int main()
{
 int n,m;
 string a;
 cin>>n;
 for(int i=1;i<=n;i++){
  cin>>a;
  mat[a]=true;//将mat[a]变成true，以便于后面判断 
 }
 cin>>m;
 for(int i=1;i<=m;i++){
  cin>>a;
  if(mat[a])cout<<a<<endl;//输进来一个就看看之前有没有出现过，如果有就输出 
 }
}
//超级简洁，18行代码搞定(((o(*ﾟ▽ﾟ*)o)))