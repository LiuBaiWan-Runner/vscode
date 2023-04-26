/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-26
 * @brief   :MT2125一样的虫子
 *          :
 *          :
 */
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const int mod = 1e5+10;
const int N = 1e5+10;

struct NODE{
    int val[6], next;
}insect[N];
int n, h[N], idx;

int F(int *a){
    ll sum = 0, pro = 1;
    for(int i = 0; i<6; i++){
        sum = (sum + a[i]) % mod;
        pro = pro * a[i] % mod;
    }
    return (sum + pro) % mod;
}

bool equal(int *a, int *b){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            bool flag = true;
            for(int k = 0; k < 6; k++){
                if(a[(i+k)%6] != b[(j+k)%6])
                    flag = false;
            }
            if(flag)
                return true;
            flag = true;
            for(int k = 0; k < 6; k++){
                if(a[(i+k)%6] != b[(j-k+6)%6])
                    flag = false;
            }
            if(flag)
                return true;
        }
    }
    return false;
}

bool find(int *a){
    int k = F(a);
    for(int i =h[k]; i != -1; i = insect[i].next){
        if(equal(insect[i].val, a)){
            return true;
        }
    }
    return false;
}

void insert(int *a){
    int k = F(a);
    memcpy(insect[idx].val, a, 6*sizeof(int));
    insect[idx].next = h[k];
    h[k] = idx;
    idx++;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    while(n--){
        int a[6];
        for(int i = 0; i < 6; i++){
            cin >> a[i];
        }
        if(find(a)){
            cout << "found." << endl;
            return 0;
        }
        else{
            insert(a);
        }
    }
    cout << "No" << endl;
    return 0;
}
