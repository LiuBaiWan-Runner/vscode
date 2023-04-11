  /*
  * @file    :1.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-02
  * @brief   :碰碰车
  *          :定义车的属性：位置、方向和这一秒是否发生运动，然后直接模拟如果两车同方向则不会碰
  *          :不同方向相距1则换个方向位置不变，不同方向相距2则在同一位置方向变化，进行模拟即可
  *          :
  */
#include <iostream>
using namespace std;

struct Car{
    int coo;
    int dir;
    bool change = true;
}car[1010];

int main()
{
    int n, t;
    cin >> n >> t;

    for(int i = 0; i<n; i++){
        cin >> car[i].coo >> car[i].dir;
        if(car[i].coo <= 0 || car[i].coo > 105) return 0;
    }

    for(int j = 0; j<t; j++){
        for(int i = 0; i<n; i++){
            if(car[i].dir == 1 && car[i].change){
                car[i].coo ++;
                car[i].change = false;
                for(int k = i+1; k<n; k++){
                    if(car[i].coo == car[k].coo && car[k].change){
                        if(car[k].dir == -1){
                            car[i].coo --;
                            car[i].dir = -1;
                            car[k].dir = 1;
                            car[i].change = false;
                            car[k].change = false;
                        }
                    }
                }
            }
            else if(car[i].dir == -1 && car[i].change){
                car[i].coo --;
                car[i].change = false;
                for(int k = i+1; k<n; k++){
                    if(car[i].coo == car[k].coo && car[k].change){
                        if(car[k].dir == 1){
                            car[i].coo ++;
                            car[i].dir = 1;
                            car[k].dir = -1;
                            car[i].change = false;
                            car[k].change = false;
                        }
                    }
                }
            }
        }
        /************************************归位************************************/
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(car[i].coo == car[j].coo){
                    car[i].dir = -car[i].dir;
                    car[j].dir = -car[j].dir;
                }
            }
        }
        for(int j = 0; j<n; j++){
            car[j].change = true;
        }
    }
    /************************************移动结束同位置变零************************************/
    // int temp;
    // if(t != 0){
    //     for(int i = 0; i<n; i++){
    //         temp = car[i].coo;
    //         for(int j = i+1; j<n; j++){
    //             if(car[j].coo == temp){
    //                 car[i].dir = 0;
    //                 car[j].dir = 0;
    //             }
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        if(i < n-1 && car[i].coo == car[i+1].coo ||
           i > 0 && car[i].coo == car[i-1].coo)
           {
            car[i].dir = 0;
           }
    }
    /************************************输出************************************/
    for(int i = 0; i<n; i++){
        cout << car[i].coo << ' ' << car[i].dir << endl;
    }
    return 0;
}