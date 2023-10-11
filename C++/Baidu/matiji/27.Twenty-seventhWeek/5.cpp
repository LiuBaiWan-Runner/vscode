/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-10-11
 * @brief   :MT2227饿饿！饭饭！
 *          :AC
 *          :
 */
#include <iostream>

using namespace std;


int main()
{
    int n, k, w, ans = 1;
    cin >> n >> k >> w;
    if(k < 3 * w){
        cout << 0;
    }
    else{
        for(int i = 0; i <= 3 * w - 1; i++){
            ans *= k - i;
        }
        cout << ans;
    }
    return 0;
}
