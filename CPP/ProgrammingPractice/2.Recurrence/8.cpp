  /*
  * @file    :8.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :Factorization
  *          :因式分解
  *          :AC
  */

#include <iostream>

using namespace std;
int a, ans;

void Factorization(int t, int a){
  if(a == 1){
    ans ++;
    return;
  }
  else{
    for(int i = t; i<=a; i++){
      if(a%i == 0){
        Factorization(i,a/i);
      }
    }
  }
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        cin >> a;
        ans = 0;
        if(a == 2){
          cout << 1 << endl;
          continue;
        }
        Factorization(2,a);
        cout << ans << endl;
    }
    
    return 0;
}
