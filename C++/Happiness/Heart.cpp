#include<iostream>
#include<Windows.h>
using namespace std;
int main()
{
	system("color F4");
	double x, y, a;
	for (y = 2.0; y > -1.5; y -= 0.1314)
	{
		for (x = -2.0; x < 2.0; x += 0.05)
		{
			a = x * x + y * y - 1;
			if (a * a * a - x * x * y * y * y <= 0)
			{
				cout << "*";
				Sleep(1);
			}
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}