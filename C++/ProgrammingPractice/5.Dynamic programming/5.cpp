/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-03-28
 * @brief   :POJ 1088滑雪（3种解法）
 *          :https://blog.csdn.net/Harington/article/details/86534326
 *          :
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int high[105][105];

int maxLen[105][105];
int to[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int max1 = 1;
struct node
{
    int x;
    int y;
    int data;
};

bool cmp(node a, node b)
{
    return a.data < b.data;
}

bool check(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= m)
        return 1;
    else
        return 0;
}
void maxL(node s[], int index)
{
    int x, y;
    x = s[index].x;
    y = s[index].y;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + to[i][0];
        int y1 = y + to[i][1];
        if (check(x1, y1))
        {
            if (maxLen[x1][y1] < maxLen[x][y] + 1 && high[x1][y1] > high[x][y])
            {
                maxLen[x1][y1] = maxLen[x][y] + 1;
                if (max1 < maxLen[x1][y1])
                {
                    max1 = maxLen[x1][y1];
                }
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    int k = 0;
    node s[10005];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> high[i][j];
            s[++k].data = high[i][j];
            s[k].x = i;
            s[k].y = j;
            maxLen[i][j] = 1; // 为什么初始化为1 想一想
        }
    }
    sort(s + 1, s + k + 1, cmp);
    for (int i = 1; i <= k; i++)
    {
        maxL(s, i);
    }
    cout << max1 << endl;

    return 0;
}