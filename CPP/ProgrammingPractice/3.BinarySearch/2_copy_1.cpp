/*
* @file    :2_copy_1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-14
* @brief   :Babelfish（c语言）
*          :https://blog.csdn.net/qq_63683485/article/details/124180614
*          :
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char en[11];
	char fn[11];
}dict;

dict a[100001];

/* 定义qsort比较函数 */
int q_cmp(const void * a,const void *b)
{
    return strcmp(((dict*)a)->fn, ((dict*)b)->fn);
}

/* 定义bsearch比较函数 */
int b_cmp(const void* a, const void* b)
{
    return strcmp((char*)a, ((dict*)b)->fn);
}

int main()
{
	char str[30];
	int i, sign;
	dict *p;
	
	i = 0;
	/* 查询标记记为"未开始" */
	sign = 1;
	/* 读取字符串直到文件结束 */
	while(gets(str))
	{
		/* 遇到空行则开始排序字典 */
		if (str[0] == '\0')
		{
			/* 查询标记记为"开始" */
			sign = 0;
			qsort(a, i, sizeof(dict), q_cmp);
			continue;
		}
		/* 查询未开始时读取字典信息 */
		if (sign)
		{
			/* 使用sscanf从str中读取查询要求 */
			sscanf(str, "%s %s", a[i].en, a[i].fn);
			i++;
		}
		/* 查询开始时进行查询 */
		else
		{
			/* 二分查找指定字符串 */
			p = (dict*) bsearch(str, a, i, sizeof(dict), b_cmp);
			/* 找到则输出结果 */
			if (p)
			{
				puts(p->en);
			}
			/* 找不到输出"eh" */
			else
			{
				puts("eh");
			}
		}
	}
	return 0;
}
