/*
* @file    :2_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/bijingrui/article/details/104265306
*          :
*          :
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
 
 
int main() {
 
	int p, e, i;// 我身上搞三个指标p e i，每隔一段时间高峰一次，求哪一天三个指标都高峰了
	int d; //指定日期
	//int cnt = 1;
	//23 28 33
	while (cin >> p >> e >> i >> d) {
		if (p == -1 && e == -1 && i == -1 && d == -1) {
			return 0;
		}
		
		/*
		假设日子是k(遍历k： d+1 ~ 21252)，三高峰出现的时机：
		(k - p) % 23 == 0  // 距离上一次高峰23天，所以今天k是p指标高峰
		(k - e) % 28 == 0 // 距离上一次高峰28天，所以今天k是e指标高峰
		(k - i) % 33 == 0 // 距离上一次高峰33天，所以今天k是i指标高峰
		*/
 
		int k;
		for (k = d + 1; (k - p) % 23 != 0; k ++); // 让k赋值了第一个p高峰
		for (; (k - e) % 28 != 0; k += 23); // 这时候k是双高峰
		for (; (k - i) % 33 != 0; k += 23 * 28); // 23 28的最小公倍数：23 * 28
		
		//printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, k - d);
		cout << k - d << endl;
 
 
 
	}
 
	return 0;
}