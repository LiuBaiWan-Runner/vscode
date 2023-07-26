# 数据结构与算法实习

数据结构与算法实习中的题目，共有十二道要求的题目，如下：

|序号|  题目名称  | 涉及知识点  |
|:--:|-----------|------------|
|1  |范围查询(Range)    |   线性结构    |
|2  |祖玛(Zuma) |   线性结构    |
|3  |灯塔(LightHouse)   |   排序    |
|4  |列车调度(Train)    |   队列、栈    |
|5  |真二叉树重构(Proper Rebuild)   |   二叉树  |
|6  |旅行商(TSP)    |图-拓扑排序    |
|7  |无线广播(Broadcast)    |图-广度遍历    |
|8  |传染链( Infectious chain) |二叉树/图   |
|9  |重名剔除(Deduplicate)  |查找-散列  |
|10 |玩具(Toy)  |状态图 |
|11 |任务调度(Schedule) |优先队列   |
|12 |循环移位(Cycle)    |字符串模式匹配 |

#### Reference：[link](https://blog.csdn.net/weixin_51060450/article/details/128208222?ops_request_misc=&request_id=&biz_id=102&utm_term=%E6%9F%90%E5%B9%BF%E6%92%AD%E5%85%AC%E5%8F%B8%E8%A6%81%E5%9C%A8%E4%B8%80%E4%B8%AA%E5%9C%B0%E5%8C%BA%E6%9E%B6%E8%AE%BE%E6%97%A0%E7%BA%BF%E5%B9%BF%E6%92%AD%E5%8F%91%E5%B0%84%E8%A3%85%E7%BD%AE%E3%80%82%E8%AF%A5%E5%9C%B0%E5%8C%BA%E5%85%B1%E6%9C%89n%E4%B8%AA%E5%B0%8F&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-128208222.nonecase&spm=1018.2226.3001.4187)


**注释要求：**
//本题的逻辑结构：线性表/队列/栈/二叉树/图 等等
//本题的存储结构：顺序/链式 等等
//解题思路和算法：输入n个点存储在s[N]中，然后依次输入 a, b 
//               然后遍历s[n]，如果a <= s[i] <= b 那么ans++,最后返回的ans就是落点数量
//效率：  时间复杂度：O(n^2)
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