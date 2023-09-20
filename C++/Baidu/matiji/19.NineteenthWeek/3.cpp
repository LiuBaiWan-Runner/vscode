/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-09
 * @brief   :MT2177密码
 *          :
 *          :
 */

#include<iostream> 
#include <cstring>
using namespace std;

const int N = 1e6 + 7;
int len, pi[N];
char s1[N], s2[N], s3[N];

void prefix_function(char *s, int len){
    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
}

int main( )
{
    cin >> s1;
    len = strlen(s1);
    strcpy(s2, s1 + 1);
    s2[strlen(s2) - 1] = '\0';
    prefix_function(s1, len);

    int temp = pi[len - 1];
    while(temp){
        strncpy(s3, s1, temp);
        s3[temp] = '\0';
        if(strstr(s2, s3)){
            cout << s3;
            return 0;
        }
        temp  = pi[temp - 1];
    }
    cout << "Just a legend";
    return 0;
}
