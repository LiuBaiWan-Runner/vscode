  /*
  * @file    :7.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :greatest common divisor
  *          :最大公约数
  *          :AC
  */
#include <iostream>

using namespace std;

int divisor(int a, int b){
    int c = a>b ? b : a;
    int m;
    for(int i = 1; i<=c; i++){
        if(a%i == 0 && b%i == 0){
            m = i;
        }
    }
    return m;
}

int main()
{
    int a, b;
    while(cin >> a >> b){
        cout << divisor(a,b) << endl;
    }
    return 0;
}
