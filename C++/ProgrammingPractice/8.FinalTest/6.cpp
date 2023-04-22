/*
 * @file    :6.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :
 *          :
 *          :AC
 */
#include <iostream>
#include <cstring>
using namespace std;

int n, c, k;
int l[200010], r[201000];
char s[201000];

int main()
{
    cin >> n >> k >> c;
    cin >> s;
    int cnt = k - 1, mx = n;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (cnt >= 0 && i < mx && s[i] == 'o')
        {
            r[cnt] = i;
            mx = i - c;
            cnt--;
        }
    }
    cnt = 0, mx = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (i > mx && s[i] == 'o')
        {
            l[cnt] = i;
            mx = i + c;
            cnt++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (l[i] == r[i])
            cout << l[i] + 1 << endl;
    }
    return 0;
}
