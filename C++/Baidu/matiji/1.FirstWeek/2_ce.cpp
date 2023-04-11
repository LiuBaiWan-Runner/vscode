  /*
  * @file    :2_ce.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-04
  * @brief   :MT2036移水造海
  *          :视频讲解例程
  *          :逐行扫描
  */
#include <iostream>

using namespace std;

// int max(int a, int b){
//     return a>b ? a : b;
// }

int main()
{
    int n, maxn = 0, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    for(int i = 1; i<=maxn; i++){
        int last = -1;
        for(int j = 0; j<n; j++){
            if(a[j]>=i){
                if(last != -1){
                    ans += j-last-1;
                }
                last = j;
            }
        }
    }
    cout << ans;
    return 0;
}
