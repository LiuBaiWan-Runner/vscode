  /*
  * @file    :count.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-02
  * @brief   :二分法求解计算中点函数值
  *          :
  *          :
  */

#include <iostream>

using namespace std;


int main()
{
    double x, y;
    for(int i = 0; i<10; i++)
    {
      cin >> x;
      if (x == -1)
      {
        break;
      }
      y = x*x*x + 4*x*x - 10;
      cout << y << endl;
    }
    
    return 0;
}
