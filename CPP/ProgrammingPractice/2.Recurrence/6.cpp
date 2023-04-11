  /*
  * @file    :6.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-07
  * @brief   :Fibonacci sequence
  *          :菲波那契数列
  *          :AC
  */
#include <iostream>

using namespace std;

int SequenceValue(int a){
    if(a == 1){
        return 1;
    }
    else if(a == 2){
        return 1;
    }
    else{
        return SequenceValue(a-1)+SequenceValue(a-2);
    }
}

int main()
{
    int n,t;
    cin >> n;
    // int a[n];
    for(int i = 0; i<n; i++){
        cin >> t;
        cout << SequenceValue(t) << endl;
    }
    // for(int i = 0; i<n; i++){
    //     cin >> a[n];
    // }
    // for(int i = 0; i<n; i++){
    //     cout << SequenceValue(a[i]) << endl;
    // }
    return 0;
}
