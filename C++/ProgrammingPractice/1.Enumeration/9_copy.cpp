/*
* @file    :9_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/xcdq_aaa/article/details/113178034
*          :
*          :
*/
#include <iostream>
using namespace std;
int all[1100];
int main() {
    int a[6], total = 0;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    for (int a1 = 0; a1 <= a[0]; a1++)                       // 1
        for (int a2 = 0; a2 <= a[1]; a2++)                   // 2
            for (int a3 = 0; a3 <= a[2]; a3++)               // 3
                for (int a4 = 0; a4 <= a[3]; a4++)           // 5
                    for (int a5 = 0; a5 <= a[4]; a5++)       // 10
                        for (int a6 = 0; a6 <= a[5]; a6++) { // 20
                            int temp = a1 + a2 * 2 + a3 * 3 + a4 * 5 + a5 * 10 +
                                       a6 * 20;
                            if (all[temp] == 0 && temp != 0) {
                                all[temp] = 1;
                                total++;
                            }
                        }
    cout << "Total=" << total;
}
