https://www.codeleading.com/article/48313127589/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cmp(int a, int b)
{
	return a > b;
}

int ans = 0;
int ans1 = 0;
int vis[1010], vis1[1010];
void fun(int a[], int b[], int n)
{
	ans = 0; ans1 = 0;
	memset(vis, 0, sizeof(vis));
	memset(vis1, 0, sizeof(vis1));
	for (int i = n-1; i >=0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] > b[j] && vis[i] == 0 && vis1[j] == 0)
			{
				ans += 3;
				ans1 += 1;
				vis[i] = 1;
				vis1[j] = 1;
				break;
			}
		}
	}
	for (int i = n-1; i >=0; i--)
	{
		for (int j = 0; j < n; j++)
			if (a[i]==b[j] && vis[i] == 0 && vis1[j] == 0)
			{
				ans += 2;
				ans1 += 2;
				vis[i] = 2;//表明这张牌已用
				vis1[j] = 2;
				break;
			}
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
		{
			ans += 1;
			ans1 += 3;
		}


	}
}
int main()
{

	int n; int a[1010], b[1010];
	while (cin >> n)
	{
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		fun(a, b, n);
		cout << ans << " ";
		fun(b, a, n);//交换一下

		cout << ans1 << endl;


	}
}