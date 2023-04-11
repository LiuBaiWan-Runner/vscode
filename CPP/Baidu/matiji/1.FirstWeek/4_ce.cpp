  /*
  * @file    :4_ce.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2042硬币塔
  *          :视频讲解例程
  *          :递归过程
  */
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
ll coin[45], glod[45];

ll find(ll n, ll i){
    if(i == 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(i <= 1){
        return 0;
    }
    if(i <= coin[n-1]+1){
        return find(n-1, i-1);
    }
    if(i <= coin[n-1]+1+n){
        return glod[n-1]+i-coin[n-1]-1;
    }
    if(i <= 2*coin[n-1]+1+n){
        return glod[n-1]+n+find(n-1,i-(coin[n-1]+1+n));
    }
    return glod[n];
}

int main()
{
    ll n, i;
    cin >> n >> i;
    coin[0] = glod[0] = 1;
    for(int j = 1; j<=n; j++){
        coin[j] = 2*coin[j-1]+j+2;
        glod[j] = 2*glod[j-1]+j;
    }
    cout << find(n,i) << endl;
    return 0;
}
