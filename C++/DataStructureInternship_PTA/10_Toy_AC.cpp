/*
 * @file    :10_Toy_AC.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-30
 * @brief   :Toy
 *          :
 *          :
 */

#include "iostream"
#include "cstdio"
#include "math.h"
 
using namespace std;
const int maxn = 40320;
const int mod = 40900;
int f[10];
int dist[maxn];
const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;
struct node {
    int a[10], val;
 
    int getcouter() {
        val = 0;
        for (int i = 1, x; i <= 8; i++) {
            x = 0;
            for (int j = i + 1; j <= 8; j++) {
                if (a[j] < a[i]) {
                    x++;
                }
            }
            val += x * f[9 - i];
        }
        return val;
    }
 
    void swap(int &x, int &y) {
        int te;
        te = x;
        x = y;
        y = te;
    }
 
    void op1() {
        for (int i = 1; i <= 4; i++) {
            swap(a[i], a[9 - i]);
        }
    }
 
    void op2() {
        a[0] = a[1];
        for (int i = 1; i <= 3; i++) {
            a[i] = a[i + 1];
        }
        a[4] = a[0];
        a[9] = a[8];
        for (int i = 8; i >= 6; i--) {
            a[i] = a[i - 1];
        }
        a[5] = a[9];
    }
 
    void op3() {
        a[0] = a[2];
        a[2] = a[3];
        a[3] = a[6];
        a[6] = a[7];
        a[7] = a[0];
    }
} que[41000];
 
void bfs() {
    node now;
    for (int i = 1; i <= 8; i++) {
        now.a[i] = i;
    }
    int from = 0, to = 0;
    dist[now.getcouter()] = 1;
    que[to++] = now;
    node op;
    while (from != to) {
        now = que[from++];
        from %= mod;
        op = now;
        op.op1();
        if (!dist[op.getcouter()]) {
            que[to++] = op;
            to %= mod;
 
            dist[op.getcouter()] = dist[now.val] + 1;
        }
 
        op = now;
        op.op2();
        if (!dist[op.getcouter()]) {
            que[to++] = op;
            to %= mod;
 
            dist[op.getcouter()] = dist[now.val] + 1;
        }
 
        op = now;
        op.op3();
        if (!dist[op.getcouter()]) {
            que[to++] = op;
            to %= mod;
            dist[op.getcouter()] = dist[now.val] + 1;
        }
    }
 
}
 
void init() {
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= 8; i++) {
        f[i] = f[i - 1] * (i - 1);
    }
}
 
 
int main() {
    init();
    bfs();
    node x;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &x.a[j]);
        }
        printf("%d\n", dist[x.getcouter()] - 1);
    }
    return 0;
}

//本题的逻辑结构：线性表/队列 等等
//本题的存储结构：顺序 等等
//解题思路和算法：由于所有的状态为8的全排列有 8 ! = 40320 种状态，可以利用康托展开建立双映射关系
//               一个康托数对应一个排列,同时，一个排列对应一个康托数
//               可以从反推，以初始状态init开始进行变换，借助队列对所有状态进行广度优先遍历（bfs)
//               最先达到给出的状态的变换次数就为最小变换次数，只需要将给出状态按照操作序列从后往前反方向进行三个变换即可还原
//效率：  时间复杂度：O(n^2)
//        空间复杂度：O(n)
/*测试数据：
输入：
2
1 2 3 4 5 6 7 8
8 6 3 5 4 2 7 1

-------------------------
输出：
0
2

*/