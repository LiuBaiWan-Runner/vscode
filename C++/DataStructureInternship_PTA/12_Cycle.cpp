/*
 * @file    :12_Cycle.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-25
 * @brief   :Cycle
 *          :输入两个字符串s1和s2，判断两个字符串长度是否相等，若不相等直接输出"NO"并结束程序
 *          :令字符串s = s1 + s1，若s2是s的子串（s.find(s2)返回s2在s中的位置）
 *          :则s1可以通过若干次循环移位得到s2，否则（s.find(s2)返回-1）则不能
 */
#include <iostream>
using namespace std;

int n;
string s1, s2, s;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            cout << "NO" << endl;
            return 0;
        }
        s = s1 + s1;
        if (s.find(s2) == -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}

//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：输入两个字符串s1和s2，判断两个字符串长度是否相等，若不相等直接输出"NO"并结束程序
//               令字符串s = s1 + s1，若s2是s的子串（s.find(s2)返回s2在s中的位置）
//               则s1可以通过若干次循环移位得到s2，否则（s.find(s2)返回-1）则不能
//效率：  时间复杂度：O(n)
//        空间复杂度：O(1)
/*测试数据：
输入：
4
AACD CDAA
ABCDEFG EFGABCD
ABCD ACBD
ABCDEFEG ABCDEE

-------------------------
输出：
YES
YES
NO
NO

*/