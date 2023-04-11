  /*
  * @file    :4.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2042硬币塔
  *          :错误
  *          :
  */
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
ll coin[45], glod[45];

ll find(int n, ll i){
    if(i == 0){
        return 0;
    }
    else if(n == 0 && i != 0){
        return 1;
    }
    else if(i == 1){
        return 0;
    }
    else if(i > 1 && i <= coin[n-1]+1){
        return find(n-1, i-1);
    }
    else if(i > coin[n-1]+1 && i <= coin[n-1]+1+n){
        return glod[n-1]+i-coin[n-1]-1;
    }
    else if(i > coin[n-1]+1+n && i <= 2*coin[n-1]+1+n){
        return glod[n-1]+n+find(n-1,i-(coin[n-1]+1+n));
    }
    else{
        return glod[n];
    }
}

int main()
{
    int n;
    ll i;
    cin >> n >> i;
    coin[0] = glod[0] = 1;
    for(int j = 1; j<=n; j++){
        coin[j] = 2*coin[j-1]+j+2;
        glod[j] = 2*glod[j-1]+j;
    }
    cout << find(n,i) << endl;
    return 0;
}
