#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10000 
int main(){
    // string s[MAX];
    // int i = 0;
    // char temp;
    // while((temp=cin.get())!=' '){
    //     s[i] +=temp;
    //     i++;
    // }
    // cout << s[0] << endl;
    // cout << i << endl;

    string str[MAX];
    char temp;
    int m = 0;
    while((temp=cin.get())!='\n'){
        if(temp == ' '){
            m++;
            continue;
        }
        str[m] +=temp;
    }
    // cout << str[2] << endl;
    for(int i = 0; i <= m; i++){
        char ch=str[i][0];
        cout << ch << endl;
    }
    
    // int m = 0;
    // for(int k = 0; k<s.size(); k++){
    //     if(s[k] = ' '){
    //         m++;
    //         continue;
    //     }
    //     else{
    //         str[m] += s[k];
    //         cout << str[m] << endl;
    //     }
    // }
    // for(int i = 0; i<m; i++){
    //     cout << str[i] ;
    // }


    // string str;
    // char temp;
    // while((temp=cin.get())!='\n'){
    //     if(temp != ' '){
    //         str +=temp;
    //     }
        
    // }
    // const int LEN =str.length();
    // char* dest = new char[LEN];
    // for(int i = 0; i<LEN; i++){
    //     dest[i]=str[i];
    //     cout << str[i] << endl;
    //     cout << dest[i];
    // }
    // cout << ' ' << dest[9] << dest[1] << endl;
    // delete []dest;
    return 0;
}