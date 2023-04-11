  /*
  * @file    :3_ce.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2016数据流的中位数
  *          :视频讲解例程 
  *          :优先队列：最大堆和最小堆
  */
#include <iostream>
#include <queue>
using namespace std;
priority_queue<float, vector<float>, less<float>> qLess;
priority_queue<float, vector<float>, greater<float>> qGreater;

void insert(int num){
    if(qLess.size()>qGreater.size()){
        qLess.push(num);
        qGreater.push(qLess.top());
        qLess.pop();
    }
    else{
        qLess.push(num);
        if(qGreater.size()!=0 && qLess.top()>qGreater.top()){
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
            if(qLess.size()>qGreater.size()){
                cout << qLess.top() << endl;
            }
            else{
                cout << (qLess.top()+qGreater.top())/2 << endl;
            }
        }
    }
    return 0;
}
