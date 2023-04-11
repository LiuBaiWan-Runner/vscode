/*
* @file    :7.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :
*          :
*          :
*/
#include <iostream>
#include <cmath>
 
using namespace std;
 
bool isprime(int x)
{
    if (x < 2)
        return false;
    int n = static_cast<int>(sqrt(x));
    for (int i = 2; i <= n; i++)
        if (x % i == 0)
            return false;
    return true;
}
 
int main()
{
    int s, r = 0;
    cin >> s;
    for (int i = 2; i < s - 2; i++)
    {
        int j = s - i;
        if (isprime(i) && isprime(j))
        {
            int k = i * j;
            if (k > r)
                r = k;
        }
    }
    cout << r;
    return 0;
}