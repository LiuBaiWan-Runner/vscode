#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char src[50] = "Hello AnxJing.AI!!!";

    /* Large enough to store content of src */
    char dest[50];
    char tmp[50];

    strcpy(tmp,src+3);
    cout << tmp << endl;
    src[3] = 'a';
    cout << src << endl;
    strcpy(src+3+1,tmp);
    cout << src << endl;
    strcpy(tmp,src+10);
    cout << tmp << endl;
    cout << strlen(tmp) << endl;
    return 0;
}