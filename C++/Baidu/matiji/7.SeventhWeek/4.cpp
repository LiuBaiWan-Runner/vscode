/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-15
 * @brief   :MT2116栈间（栈）
 *          :栈的操作＋输出中间元素
 *          :可以使用数组进行模拟，cout和cin会超时，使用scanf和printf
 */
#include <iostream>

using namespace std;

const int N = 5e6+5;

int n, st[N], op, x;

int main()
{

    cin >> n;
    while(n--){
        scanf("%d", &op);
        // cin >> op;
        switch(op){
            case 1:{
                // cin >> x;
                scanf("%d", &x);
                st[++*st] = x;
                break;
            }
            case 2:{
                printf("%d\n", st[*st]);
                // cout << st[*st] << endl;
                break;
            }
            case 3:{
                // cin >> x;
                scanf("%d", &x);
                // cout << st[x + 1] << endl;
                printf("%d\n", st[x + 1]);
                break;
            }
            case 4:{
                if(*st)
                    --*st;
                break;
            }
        }
    }
    return 0;
}
