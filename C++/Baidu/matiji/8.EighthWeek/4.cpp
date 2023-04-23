/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :MT2117双端队列
 *          :
 *          :
 */
#include <iostream>
#include <deque>
using namespace std;
deque<int> q;
int n, op, x;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op;
        switch(op){
            case 1:{
                cin >> x;
                q.push_front(x);
                break;
            }
            case 2:{
                cin >> x;
                q.push_back(x);
                break;
            }
            case 3:{
                cout << q.front() << endl;
                break;
            }
            case 4:{
                cout << q.back() << endl;
                break;
            }
            case 5:{
                q.pop_front();
                break;
            }
            case 6:{
                q.pop_back();
                break;
            }
        }
    }
    return 0;
}
