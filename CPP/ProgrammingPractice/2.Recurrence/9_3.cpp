  /*
  * @file    :9_3.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-09
  * @brief   :逆波兰表达式
  *          :https://blog.csdn.net/C_Dreamy/article/details/104085353?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167831938616800180671913%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=167831938616800180671913&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-104085353-null-null.142^v73^insert_down3,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%98%AF%E4%B8%80%E7%A7%8D%E6%8A%8A%E8%BF%90%E7%AE%97%E7%AC%A6%E5%89%8D%E7%BD%AE%E7%9A%84%E7%AE%97%E6%9C%AF%E8%A1%A8%E8%BE%BE%E5%BC%8F%EF%BC%8C%E4%BE%8B%E5%A6%82%E6%99%AE%E9%80%9A%E7%9A%84%E8%A1%A8%E8%BE%BE%E5%BC%8F2%20%2B%203%E7%9A%84%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E7%A4%BA%E6%B3%95%E4%B8%BA%2B%202%203%E3%80%82%E9%80%86%E6%B3%A2%E5%85%B0&spm=1018.2226.3001.4187
  *          :AC(copy)
  */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define A 1
 
using namespace std;
 
int count=0;
char ch[A];
 
inline double caculate()
{
    cin>>ch;
 
    if(ch[0]=='+') return caculate()+caculate();
    else if(ch[0]=='-') return caculate()-caculate();
    else if(ch[0]=='*') return caculate()*caculate();
    else if(ch[0]=='/') return caculate()/caculate();
    else return atof(ch);
}
 
int main()
{
    printf("%lf",caculate());
 
    return 0;
}