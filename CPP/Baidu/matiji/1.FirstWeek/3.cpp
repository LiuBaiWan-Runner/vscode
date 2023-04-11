  /*
  * @file    :3.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2016数据流的中位数
  *          :视频讲解例程 后自己修改
  *          :优先队列：最大堆和最小堆
  */

#include <iostream>
#include <queue>
using namespace std;
priority_queue<float, vector<float>, less<float>> qLess;
priority_queue<float, vector<float>, greater<float>> qGreater;

void insert(int num){
    if(qLess.size()<qGreater.size()){
        qGreater.push(num);
        qLess.push(qGreater.top());
        qGreater.pop();
    }
    else{
        qGreater.push(num);
        if(qLess.size()!=0 && qLess.top()>qGreater.top()){
            qLess.push(qGreater.top()), qGreater.pop();
            qGreater.push(qLess.top()), qLess.pop();
        }
    }
}

int main()
{
    int n, num;
    cin >> n;
    while(n--){
        char c;
        cin >> c;
        if(c == '+'){
            cin >> num;
            insert(num);
        }
        else{
            if(qLess.size()<qGreater.size()){
                cout << qGreater.top() << endl;
            }
            else{
                cout << (qLess.top()+qGreater.top())/2 << endl;
            }
        }
    }
    return 0;
}
