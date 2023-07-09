/*
 * @file    :4.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-09
 * @brief   :MT2174建立数据库
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 7;
int n;
char str[35];

struct TRIE
{
    int nex[N][26], cnt, exist[N];

    void insert(char *s, int l){
        int p = 0;
        for(int i = 0; i < l; i++){
            int c = s[i] - 'a';
            if(!nex[p][c]){
                nex[p][c] = ++cnt;
            }
            p = nex[p][c];
        }
        exist[p]++;
    }
    int find(char *s, int l){
        int p = 0;
        for(int i = 0; i < l; i++){
            int c = s[i] - 'a';
            if(!nex[p][c]){
                return 0;
            }
            p = nex[p][c];
        }
        return exist[p];
    }
}trie;

int main()
{
    cin >> n;
    while(n--){
        cin >> str;
        int temp = trie.find(str, strlen(str));
        if(!temp){
            cout << "OK" << endl;
        }
        else{
            cout << str << temp << endl;
        }
        trie.insert(str, strlen(str));
    }
    return 0;
}
