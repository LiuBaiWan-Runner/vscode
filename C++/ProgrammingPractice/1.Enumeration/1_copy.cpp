/*
* @file    :1_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/Garyboyboy/article/details/112129945?ops_request_misc=&request_id=&biz_id=102&utm_term=%E8%B5%9B%E5%88%A9%E6%9C%8912%E6%9E%9A%E9%93%B6%E5%B8%81%E3%80%82%E5%85%B6%E4%B8%AD%E6%9C%8911%E6%9E%9A%E7%9C%9F%E5%B8%81%E5%92%8C1%E6%9E%9A%E5%81%87%E5%B8%81%E3%80%82%E5%81%87%E5%B8%81%E7%9C%8B%E8%B5%B7%E6%9D%A5%E5%92%8C%E7%9C%9F&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-112129945.142^v76^insert_down38,201^v4^add_ask,239^v2^insert_chatgpt&spm=1018.2226.3001.4187
*          :
*          :
*/
//假币问题
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

char Left[3][7];
char Right[3][7];
char result[3][7];
//判断假币函数，两种情况，一种重一点，一种轻一点
bool isFake(char c, bool light);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; ++i) 
			cin >> Left[i] >> Right[i] >> result[i];
			//开始枚举
		for (char c = 'A'; c <= 'L'; c++)
		{
			if (isFake(c, true))
			{
				cout << c << " is the counterfeit coin and it is light. " << endl;
				break;
			}
			else if (isFake(c, false))
			{
				cout << c << " is the counterfeit coin and it is heavy. " << endl;
				break;
			}
		}
	}

	return 0;
}


bool isFake(char c, bool light)
{
	for (int i = 0; i < 3; ++i)
	{
		char* pl, * pr;
		if (light)
		{
			pl = Left[i];
			pr = Right[i];
		}

		else
		{
			pl = Right[i];
			pr = Left[i];
		}
		switch (result[i][0])
		{
		case 'u':
			if (strchr(pr, c) == NULL)
				return  false;
			break;
		case 'e':
			if (strchr(pr, c) || strchr(pl, c))
				return  false;
			break;
		case 'd':
			if (strchr(pl, c) == NULL)
				return  false;
			break;
		}
	}
	return true;
}
