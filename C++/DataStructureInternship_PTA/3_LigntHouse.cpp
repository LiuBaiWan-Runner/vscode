/*
 * @file    :3_LigntHouse.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :LigntHouse
 *          :定义灯塔结点，包含横纵坐标，定义灯塔数组L[N]，然后依次输入坐标
 *          :然后从头开始循环，将L[i]与它后边的灯塔进行比较，如果可以互相照亮那么ans++，直到所有的灯塔都进行了一次判断
 *          :
 */
#include <iostream>

using namespace std;

const int N = 4e6+6;

struct LightHouse{
    int x, y;
}L[N]; //灯塔坐标节点，初始化数组L[N]

int n, ans = 0;

int answer();

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> L[i].x >> L[i].y;
    }
    
    cout << answer() << endl;
    return 0;
}

// 枚举求得结果
// 相互照亮意味着一个灯塔在另一个的左下或者右上方，即横纵坐标之差的符号相同
int answer(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((L[j].x - L[i].x) * (L[j].y - L[i].y) > 0){ //验证横纵坐标的符号相同
                ans++;
            }
        }
    }
    return ans;
}


//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：定义灯塔结点，包含横纵坐标，定义灯塔数组L[N]，然后依次输入坐标
//               然后从头开始循环，将L[i]与它后边的灯塔进行比较，如果可以互相照亮那么ans++，直到所有的灯塔都进行了一次判断
//效率：  时间复杂度：O(n^2)
//        空间复杂度：O(n)
/*测试数据：
输入：
3
2 2
4 3
5 1

-------------------------
输出：
1

*/