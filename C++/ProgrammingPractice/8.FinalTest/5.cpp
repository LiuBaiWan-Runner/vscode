/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :
 *          :
 *          :
 */
#include <iostream>
#include <algorithm>
#define MAX 100
#define INF (1 << 21)
using namespace std;
int C[MAX];
int main()
{
    int m, n;
    cin >> m >> n;
    C[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    sort(C + 1, C + n + 1);
    int T[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
                T[i][j] = 0;
            else
                T[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j < C[i])
                T[i][j] = T[i - 1][j];
            else
                T[i][j] = min(T[i - 1][j], T[i][j - C[i]] + 1);
            // cout << T[i][j] << " ";
        }
    }
    cout << T[n][m] + 2 << endl;
    return 0;
}