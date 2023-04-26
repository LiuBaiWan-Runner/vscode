/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-12
 * @brief   :MT2122事务处理（堆）
 *          :维护一个大根堆q,输入一个新事务时，先处理已存在的事务
 *          :处理正在进行的事务，暂停事务，更新数据之后在循环输入新的事务，输出按优先级输出队列事务即可
 */
#include <iostream>
#include <queue>
using namespace std;

struct Process
{
    int ai, ti, fi, vi;
    bool operator < (const Process &b) const{
        if(vi != b.vi){
            return vi < b.vi;
        }
        else{
            return ti > b.ti;
        }
    }
    bool read(){
        return (scanf("%d%d%d%d", &ai ,&ti, &fi, &vi) != EOF);
    }
}now, tp;

priority_queue <Process> q;

int main()
{
    int time, x;
    while(now.read()){
        x = now.ti - time;
        while(!q.empty()){
            tp = q. top();
            q.pop();
            if(tp.fi <= x){
                x -= tp.fi;
                time += tp.fi;
                cout << tp.ai << " " << time << endl;
            }
            else{
                tp.fi -= x;
                q.push(tp);
                break;
            }
        }
        time += x;
        q.push(now);
    }
    while(!q.empty()){
        tp = q.top();
        q.pop();
        time += tp.fi;
        cout << tp.ai <<" " << time << endl;
    }
    return 0;
}
