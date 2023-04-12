/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-12
 * @brief   :MT2122事务处理
 *          :
 *          :
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
