  /*
  * @file    :1_ce.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-02
  * @brief   :MT2033碰碰车
  *          :视频讲解例程
  *          :通过找规律排序
  */
#include <iostream>
#include <algorithm>
using namespace std;

struct Car {
    int ID;
    int x;
    int f;
}car[1010];

bool cmpx(Car a, Car b){
    return a.x <= b.x;
}
bool cmpID(Car a, Car b){
    return a.ID <= b.ID;
}

int n, t, tmp[1010];

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> car[i].x >>car[i].f;
        car[i].ID = i+1;
    }
    sort(car, car+n, cmpx);
    for (int i = 0; i < n; i++)
    {
        tmp[i] = car[i].ID;
        car[i].x = car[i].x + car[i].f * t;
    }
    sort(car, car+n, cmpx);
    for (int i = 0; i < n; i++)
    {
        car[i].ID = tmp[i];
        if(i < n-1 && car[i].x == car[i+1].x ||
           i > 0 && car[i].x == car[i-1].x)
           {
            car[i].f = 0;
           }
    }
    sort(car, car+n, cmpID);
    for(int i = 0; i<n; i++){
        cout << car[i].x << " " << car[i].f << endl;;
    }
    return 0;
}
