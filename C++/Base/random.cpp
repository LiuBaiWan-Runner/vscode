  /*
  * @file    :random.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-01-03
  * @brief   :test
  *          :
  *          :
  */

#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    int num = rand() % 100 + 1;
    if(num>50){
        cout<<"Nice"<<endl;
    }
    else{
        cout<<"Bad"<<endl;
    }
    
}