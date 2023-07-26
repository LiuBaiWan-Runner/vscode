/*
 * @file    :1_Range.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :Range
 *          :线性结构
 *          :输入n个点存在s[N]中，然后依次输入 a, b 
 *          :然后遍历s[n]，如果a <= s[i] <= b 那么ans++,最后返回的ans就是落点数量
 */
#include <iostream>

using namespace std;

const int N = 5e5+7;
int n, m, a, b, ans;
int s[N];

int search(int a, int b){   //查询是否在区间[a,b]内
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] >= a && s[i] <= b){
            ans++; //s[i]在[a,b]内，+1
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    while(m--){
        cin >> a >> b;
        cout << search(a, b) << endl;
    }
    return 0;
}


//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：输入n个点存储在s[N]中，然后依次输入 a, b 
//               然后遍历s[n]，如果a <= s[i] <= b 那么ans++,最后返回的ans就是落点数量
//效率：  时间复杂度：O(n*m)
//        空间复杂度：O(n)
/*测试数据：
输入：
5 2
1 3 7 9 11
4 6
7 12
-------------------------
输出：
0
3

*/