/*
* @file    :6.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :
*          :
*          :
*/
#include <iostream>
using namespace std;
int main() {
    int n, max = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if ((i + j) % 2 == 0 && (j + k) % 3 == 0 &&
                    (i + j + k) % 5 == 0) {
                    if (i + j + k > max)
                        max = i + j + k;
                }
            }
        }
    }
    cout << max;
}
