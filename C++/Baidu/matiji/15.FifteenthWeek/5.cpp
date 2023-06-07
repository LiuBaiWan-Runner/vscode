/*
 * @file    :5.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-06-07
 * @brief   :MT2162连锁反应
 *          :
 *          :
 */
#include <iostream>

using namespace std;
int n, ans;
char a[7][7], b[7][7];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void turn(int x, int y){
    b[x][y] ^= 1;
    for(int i  = 0; i < 4; i++){
        if(x + dx[i] > 0 && 
           x + dx[i] < 6 &&
           y + dy[i] > 0 &&
           y + dy[i] < 6){
            b[x + dx[i]][y + dy[i]] ^= 1;
        }
    }
}

int main()
{
    cin >> n;
    while(n--){
        ans = 0x3f3f3f3f;
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
            }
        }
        for(int op = 0; op < 32; op++){
            int cnt = 0;
            for(int i = 1; i <= 5; i++){
                for(int j = 1; j <= 5; j++){
                    b[i][j] = a[i][j];
                }
            }
            for(int i = 1; i <= 5; i++){
                if(op & (1 << (i - 1))){
                    turn(1, i), cnt++;
                }
            }
            for(int i = 2; i <= 5; i++){
                for(int j = 1; j <= 5; j++){
                    if(b[i - 1][j] == '0'){
                        turn(i, j), cnt++;
                    }
                }
            }
            bool flag = true;
            for(int i = 1; i <= 5; i++){
                if(b[5][i] == '0'){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = min(ans, cnt);
            }
        }
        if(ans > 6){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
