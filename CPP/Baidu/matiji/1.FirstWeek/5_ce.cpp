  /*
  * @file    :5_ce.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2041三角形的个数
  *          :视频讲解例程
  *          :找规律 视频规律和自己总结规律
  */
#include <iostream>

using namespace std;

int fun(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    return (n-1)*n/2 + fun(n-2);
    // return fun(n-2)+n-1+(n-1)*(n-2)/2;
}

int main()
{
    int n, N;
    cin >> N;
    while(N--){
        cin >> n;
        int sum1 = 0, sum2 = 0;
        for(int i = 1; i<=n; i++){
            sum1 += (n-i+1)*(n-i+2)/2;
            // sum1 += i+(i*(i-1))/2;
        }
        sum2 = fun(n);
        cout << sum1+sum2 << endl;
    }
    return 0;
}
