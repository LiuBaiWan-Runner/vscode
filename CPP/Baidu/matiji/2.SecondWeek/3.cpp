/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-10
* @brief   :MT2068高数考试
*          :模拟将分数赋给每一个人，然后输出最小的.可使用差分数组优化
*          :AC
*/
#include <iostream>

using namespace std;


int main()
{
    int n, p;
    cin >> n >> p;
    int score[n];
    int a, b, add;
    for(int i = 0; i<n; i++){
        cin >> score[i];
    }
    for(int i = 0; i<p; i++){
        cin >> a >> b >> add;
        for(int j = a-1; j<b; j++){
            score[j] +=add;
        }
    }
    int min = 32767;
    for(int i = 0; i<n; i++){
        if(score[i] < min){
            min = score[i];
        }
    }
    cout << min << endl;
    return 0;
}
