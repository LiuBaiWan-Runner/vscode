/*
 * @file    :10_Toy.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-24
 * @brief   :Toy
 *          :由于所有的状态为8的全排列有 8 ! = 40320 种状态，可以利用康托展开建立双映射关系
 *          :一个康托数对应一个排列,同时，一个排列对应一个康托数
 *          :可以从反推，以初始状态init开始进行变换，借助队列对所有状态进行广度优先遍历（bfs)
 *          :最先达到给出的状态的变换次数就为最小变换次数，只需要将给出状态按照操作序列从后往前反方向进行三个变换即可还原
 *          :康托展开：https://blog.csdn.net/ltrbless/article/details/87696372?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169019677616800184110888%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169019677616800184110888&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-87696372-null-null.142^v91^insertT0,239^v3^insert_chatgpt&utm_term=%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80&spm=1018.2226.3001.4187
 */
#include <iostream>
#include <queue>
using namespace std;

const int N = 5e4;

struct Node{
    string seq = ""; // 操作序列
    int value = -1; // 康托数
    Node(string s, int value):
        seq(s), value(value){}
};

queue<Node> q; // 创建结点队列
int n, cantorNum, count; // 玩具总数，开始状态的康托数，变换次数
int init[8] = {1, 2, 3, 4, 8, 7, 6, 5}, start[8]; // 初始状态数组，当前状态数组
int fac[9] = {1,1,2,6,24,120,720,5040,40320}; // 阶乘数组
bool flag; // 循环结束标志

void create_start(); // 创建当前状态数组
int cantor(int* arr); // 康托函数，求康托数
void inverse_cantor(int value, int* arr); // 逆康托函数，由康托数得到排列数组
void operate(bool* hashcode, Node tmp); // 执行变换操作

int main()
{
    cin >> n;
    while(n--){
        flag = true;
        count = 0;
        bool hashcode[N] = {false};

        create_start();
        cantorNum = cantor(start); // 开始状态的康托数
        

        Node initNode("", cantor(init)); // 创建初始结点，并计算康托数
        q.push(initNode); // 初始结点压入入队列

        while(flag){
            int q_len = q.size();
            for(int i = 0; i < q_len; i++){
                Node tmp = q.front(); // 临时结点等于队前结点
                q.pop(); // 队前出队
                if(tmp.value == cantorNum){ // 结束条件：当前队前结点的康托数等于开始状态的康托数
                    flag = false;
                    cout << count << endl;
                    break;

                    // 输出由初始状态变换到当前状态的操作序列
                    cout << tmp.seq << endl;
                    break;
                    // 操作太多分行输出
                    int len = tmp.seq.size(), rowNum = len / 60; // 计算输出行数
                    char ch[N];
                    for(int k = 0; k < len; k++){
                        ch[k] = tmp.seq[k];
                    }
                    for (int row = 0; row <= rowNum; row++){ // 每行60个字符
                        for (int j = 0; j < 60; j++){
                            cout << ch[j + 60 * row] << ' ';
                        }
                        cout << endl;
                    }
                    break;
                }
                operate(hashcode,tmp);  // 从初始状态进行操作,将操作变换结果入队
            }
            count++; // 操作次数+1
            if(count > N){ // 无法还原
                flag = false;
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}

// 创建当前状态数组
void create_start(){
    for(int i = 0; i < 4; i++){
        cin >> start[i];
    }
    for(int i = 7; i > 3; i--){
        cin >> start[i];
    }
}

// 康托函数，求康托数
int cantor(int* arr){
    int num = 0;    // 康托数
    for(int i = 0; i < 7; i++){
        int cnt = 0;
        for(int j = i + 1; j < 8; j++){
            if(arr[j] < arr[i]){
                cnt ++; // 后边有几个数比当前数小
            }
        }
        num += cnt * fac[7 - i];
    }
    return num;
}

// 逆康托函数，由康托数得到排列数组
void inverse_cantor(int value, int* arr){
    int t[8] = {0}, j, l;
    for(int i = 0; i < 8; i++){
        int less = value / fac[7 - i]; // 后面数字中比它小的数字数量
        value -= less * fac[7 - i];
        for(j = 0, l = 0; l <= less; j++){
            if(t[j] == 0){
                l++;
            }
        }
        t[j - 1] = 1; // 标记已经在前边出现的数字，这样可以跳过l++，然后使j++
        arr[i] = j;
    }
}

// A，B，C三种变换操作
// 操作时，根据康托数value得到变换前的排列before，进行排列的变化，然后计算并返回变换后的排列res的康托数
int A(int value){ // 交换行
    int before[8], res[8];
    inverse_cantor(value,before);
    res[0] = before[4];
    res[1] = before[5];
    res[2] = before[6];
    res[3] = before[7];
    res[4] = before[0];
    res[5] = before[1];
    res[6] = before[2];
    res[7] = before[3];
    return cantor(res);
}

int B(int value){ // 循环右移
    int before[8], res[8];
    inverse_cantor(value,before);
    res[0] = before[3];
    res[1] = before[0];
    res[2] = before[1];
    res[3] = before[2];
    res[4] = before[7];
    res[5] = before[4];
    res[6] = before[5];
    res[7] = before[6];
    return cantor(res);
}

int C(int value){ // 中心顺时针旋转
    int before[8], res[8];
    inverse_cantor(value, before);
    res[0] = before[0];
    res[1] = before[5];
    res[2] = before[1];
    res[3] = before[3];
    res[4] = before[4];
    res[5] = before[6];
    res[6] = before[2];
    res[7] = before[7];
    return cantor(res);
}

// 执行变换操作
void operate(bool* hashcode, Node tmp){
    int a = A(tmp.value), b = B(tmp.value), c = C(tmp.value);
    // 判断三种操作后产生的情况是否出现过，没有则入队，并记录相应的操作步骤
    if(!hashcode[a]){
        hashcode[a] = true;
        string s1 = tmp.seq + "A";
        Node t1(s1, a);
        q.push(t1);
    }
    if(!hashcode[b]){
        hashcode[b] = true;
        string s2 = tmp.seq + "B";
        Node t2(s2, b);
        q.push(t2);
    }
    if(!hashcode[c]){
        hashcode[c] = true;
        string s3 = tmp.seq + "C";
        Node t3(s3, c);
        q.push(t3);
    }
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