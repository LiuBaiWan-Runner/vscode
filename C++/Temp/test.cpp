#include <iostream>

using namespace std;


int main()
{
    int i = 2;
    int a[6] = {0,1,2,3,4,5};
    cout << i << endl;
    cout << a[i++] << endl;
    cout << i << endl;
    cout << a[++i] << endl;
    return 0;
}
