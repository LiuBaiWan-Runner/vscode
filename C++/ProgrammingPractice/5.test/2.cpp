/*
* @file    :2.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-01
* @brief   :捕食关系
*          :参考：https://www.cnblogs.com/PushyTao/p/14507411.html#C__120
*          :
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll N = 2e4+10;
ll a[N],ans,b[N], temp;
int n,m;
int main()  
{
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int j=1;j<=n;j++){
        cin >> b[j];
    }

    sort(a+1,a+1+m);
    sort(b+1,b+1+n);

    for(int i=1;i<=m;i++){
        for(int j = temp+1; j<=n; j++){
            if(a[i] > b[j]){
                temp++;
            }
            else{
                break;
            }
        }
        ans += temp;
    }
    cout<<ans<<endl;
    return 0;
}
