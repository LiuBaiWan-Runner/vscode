#include <bits/stdc++.h>
#define MX 100000
using namespace std;
int a[MX + 10],L,R,mid,x,n,q;
int Lfind(int L,int R)
{
    while(L <= R)
    {
        mid = L + ((R - L) / 2);
        if(a[mid] == x)
        {
            R = mid - 1;
        }
        else if(a[mid] < x)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    if(L > n || a[L] != x)
    {
        return -1;
    }
    else
    {
        return L;
    }
}
int Rfind(int L,int R)
{
    while(L <= R)
    {
        mid = L + ((R - L) / 2);
        if(a[mid] == x)
        {
            L = mid + 1;
        }
        else if(a[mid] < x)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    if(R < 1 || a[R] != x)
    {
        return -1;
    }
    else
    {
        return R;
    }
}
int main()
{
    int i;
    cin >> n >> q;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while(q--)
    {
        L = 1,R = n;
        cin >> x;
        cout << Lfind(L,R) << ' ' << Rfind(L,R) << endl;;
    }
    return 0;
}