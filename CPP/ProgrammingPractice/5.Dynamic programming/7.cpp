/*
* @file    :7.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-28
* @brief   :poj 1390:Blocks 方盒游戏
*          :https://blog.csdn.net/abc15766228491/article/details/79725409
*          :
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct block{
    int color;  //这个块的颜色
    int len;  //这个块的大小
    block(int _color, int _len):color(_color), len(_len){};
};
vector<block> n_v;
int info[200][200][200];
int dp(int l, int r, int ex_len){
    if(info[l][r][ex_len]>0) return info[l][r][ex_len];
    if(l==r) return (n_v[l].len+ex_len)*(n_v[l].len+ex_len);
    int temp = dp(l, r-1, 0)+(ex_len+n_v[r].len)*(ex_len+n_v[r].len);
    for (int k = r-1; k >= l ; k--) {
        if(n_v[k].color == n_v[r].color){
            //找到一个合适的了
            temp = max(temp, dp(l, k, ex_len+n_v[r].len)+dp(k+1, r-1, 0));
        }
    }
    info[l][r][ex_len] = temp;
    return temp;
}
int main()
{
    int t, c=1;
    cin>>t;    //多少个测试用例
    while(t--){
        memset(info, 0, sizeof(info));
        n_v.clear();
        int n;     //多少个盒子
        cin>>n;
        int num;
        cin>>num;
        n_v.push_back(block(num, 1));
        for (int i = 1; i < n; ++i) {
            cin>>num;
            if(num==(n_v.end()-1)->color){
                //和上一个颜色块的颜色一样，放到同一个结构体里面
                (n_v.end()-1)->len++;
            }
            else{
                //颜色不同，新加一个结构体元素
                n_v.push_back(block(num, 1));
            }
        }
        cout<<"Case "<<c++<<": "<<dp(0, n_v.size()-1, 0)<<endl;
    }
    return 0;
}
/*
2
9
1 2 2 2 2 3 3 3 1
1
1
*/