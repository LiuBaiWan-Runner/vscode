https://blog.csdn.net/qq_41505957/article/details/95763521

#include <stdio.h>
#include <algorithm>
using namespace  std;
#define N 20020
int a[N];
int cmp(int a, int b) {
	return a > b ;
}
int main()
{
	int n, b, i, sum;
	scanf("%d%d", &n, &b);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, cmp);
	sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum >= b)
			break;
	}
	printf("%d\n", i + 1);
	return 0;
}