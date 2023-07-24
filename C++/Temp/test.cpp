#include <iostream>

using namespace std;


int main()
{
    string str = "fghusadjkghyu";
    char ch[100];
    for(int i = 0; i < str.size(); i++){
        ch[i] = str[i];
    }
    for(int i = 0; i < str.size(); i++){
        cout << ch[i] << ' '
    }
    return 0;
}
