#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char str[20005];
int n;
char tmp[20005];
void cal(int t,char ch){
    char *p;
    p=str;
    strcpy(tmp,p+t);
    str[t]=ch;
    strcpy(str+t+1,tmp);
}

bool hasRepeat(){
    int len=strlen(str);
    int i=0;
    while(i<len){
        char t=str[i];
        int startpos=i;
        int times=0;
        while(i<len&&t==str[i]){
            times++;
            i++;
        }
        if(times>=3){
    strcpy(tmp,str+i);
    strcpy(str+startpos,tmp);
    return true;
        }
    }
    return false;
}
int main(){
    int t;
    char ch;
    gets(str);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %c",&t,&ch);
        cal(t,ch);
        while(hasRepeat());
        if(strlen(str)==0)
            printf("-\n");
        else printf("%s\n",str);
    }
}