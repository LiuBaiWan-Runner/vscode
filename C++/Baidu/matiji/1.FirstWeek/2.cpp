  /*
  * @file    :2.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-03
  * @brief   :移水造海
  *          :
  *          :
  */

#include <iostream>

using namespace std;

int min(int a, int b){
    return a>b ? b : a;
}

int main()
{
    int n, minh, minI, high, sum = 0;
    int leftHigh, rightHigh;
    int left, right;
    bool l,r;
    cin >> n;
    int w[n];
    for(int i = 0; i<n; i++){
        cin >> w[i];
    }

    while(true){
        minh = 10000;
        for(int i  = 1; i<n-1; i++){
            if(w[i]<minh){
                minh = w[i];
                minI = i;
            }
        }

        leftHigh = rightHigh = minh;
        l = false;
        for(int j = minI; j>=0; j--){
            if(w[j]>leftHigh){
                leftHigh = w[j];
                left = j;
                l = true;
                break;
            }
        }

        r = false;
        for(int j = minI; j<n; j++){
            if(w[j]>rightHigh){
                rightHigh = w[j];
                right = j;
                r = true;
                break;
            }
        }

        high = min(leftHigh,rightHigh);
        for(int i = left+1; i<right; i++){
            sum += (high - w[i]);
            w[i] = high;
        }

        if(!l || !r) break;
    }
    cout << sum << endl;
    

    return 0;
}
