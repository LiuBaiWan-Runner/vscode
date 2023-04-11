/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-18
* @brief   :MC0176石头剪刀布
*          :视频讲解例程
*          :AC
*/
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 20;
char B[maxn], C[maxn];
int cnt[maxn][3];

int main()
{
    int n, k;
    int t;
    int sum;
    cin >> n >> k;
    scanf("%s", B);
    scanf("%s", C);
    for(int i = 0; i<(1 << n); i++){
        t = 0;
        for(int j = 0; j<n; j++){
            if((i >> j) & 1){
                t++;
            }
        }
        if(t == k){
            t = 0;
            for(int j = 0; j<n; j++){
                if((i >> j) & 1){
                    switch (C[j])
                    {
                    case 'r':
                        cnt[t][0]++;
                        break;
                    case 's':
                        cnt[t][1]++;
                        break;
                    case 'p':
                        cnt[t][2]++;
                        break;
                    default:
                        break;
                    }
                    t++;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i<(1 << n); i++){
        t = 0;
        for(int j = 0; j<n; j++){
            if((i >> j) & 1){
                t++;
            }
        }
        if(t == k){
            t = 0;
            sum = 0;
            for(int j = 0; j<n; j++){
                if((i >> j) & 1){
                    switch (B[j])
                    {
                    case 'r':
                        sum += cnt[t][1];
                        break;
                    case 's':
                        sum += cnt[t][2];
                        break;
                    case 'p':
                        sum += cnt[t][0];
                        break;
                    default:
                        break;
                    }
                    t++;
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
