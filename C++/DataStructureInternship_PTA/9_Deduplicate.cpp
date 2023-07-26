/*
 * @file    :9_Deduplicate.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-23
 * @brief   :Deduplicate
 *          :使用动态无序数组unordered_set存储食物集（利用.count())函数查找是否已经存在）
 *          :使用动态容器（有序）vector存储结果集，便于按顺序输出
 *          :代码逻辑为：输入一个food，看这个food是否在食物集foodSet中
 *          :如果在，再看他是否在结果集ans中，如果在就不管，不在就写入ans
 *          :然后将food写入食物集foodSet中（所有输入的food都在foodSet中），继续输入下一个food
 * 
 *          foodSet     ans     operation
 *          true        true    foodSet.insert(food)
 *          true        false   ans.bush_back(food), foodSet.insert(food)
 *          false       ----    foodSet.insert(food)
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int N = 6e5 + 10;
unordered_set<string> foodSet; // 输入的无序食物集合
vector<string> ans; // 有序结果集
string food;
int n;

bool search_in_vector(vector<string> &a, string target); // 在a中查找target;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> food;
        if(foodSet.count(food) && !search_in_vector(ans, food)){
            ans.push_back(food);
        }
        foodSet.insert(food);
    }

    for(string s:ans){ // 输出结果
        cout<< s <<endl;
    }
    return 0;
}

// 在vector容器中查找是否存在某个值target，找到返回true，没找到返回false
bool search_in_vector(vector<string> &a, string target){
    vector<string>::iterator tmp;
    tmp = find(a.begin(), a.end(), target);
    if(tmp == a.end()){ // 没有找到
        return false;
    }
    return true; // 找到了
}

//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：使用动态无序数组unordered_set存储食物集（利用.count())函数查找是否已经存在）
//               使用动态容器（有序）vector存储结果集，便于按顺序输出
//               代码逻辑为：输入一个food，看这个food是否在食物集foodSet中
//               如果在，再看他是否在结果集ans中，如果在就不管，不在就写入ans
//               然后将food写入食物集foodSet中（所有输入的food都在foodSet中），继续输入下一个food
//效率：  时间复杂度：O(n^2)
//        空间复杂度：O(n)
/*测试数据：
输入：
10
brioche
camembert
cappelletti
savarin
cheddar
cappelletti
tortellni
croissant
brioche
mapotoufu

-------------------------
输出：
cappelletti
brioche

*/