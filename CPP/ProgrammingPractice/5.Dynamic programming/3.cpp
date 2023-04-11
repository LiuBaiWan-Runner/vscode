/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :HDU 1159 Common Subsequence
*          :https://blog.csdn.net/a_eagle/article/details/7213236
*          :
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int f[1100][1100];
char s1[1000], s2[1000];
int len1, len2;
int main()
{
    while(scanf("%s %s", s1, s2) != EOF)
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        memset(f, 0, sizeof(f));
        for(int i = 1;i <= len1; ++i)
        {
            for(int j = 1;j <= len2; ++j)
            {
                if(s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1]+1;
                else
                {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }
        cout << f[len1][len2] << endl;
    }
    return 0;
}