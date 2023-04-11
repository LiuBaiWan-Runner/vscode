/*
* @file    :4.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-11
* @brief   :
*          :
*          :
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression 正则表达式
using namespace std;

int main ( )
{
    string email_address;
    string user_name, domain_name;

    regex pattern("([\\w]{1,16}+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
    // 第二组（即域名），匹配规则：0至9或a至z之中的任意字符重复一遍或以上，
    // 接着一个点，接着a至z之中的任意字符重复2至3遍（如com或cn等），
    // 第二组内部的一组，一个点，接着a至z之中的任意字符重复2遍（如cn或fr等）
    // 内部一整组重复零次或一次

    cin >> email_address
    if ( regex_match( email_address, pattern ) )
    {
        cout << "您输入的电子邮件地址合法" << endl;


        // 截取第一组
        user_name = regex_replace( email_address, pattern, string("$1") );


        // 截取第二组
        domain_name = regex_replace( email_address, pattern, string("$2") );


        cout << "用户名：" << user_name << endl;
        cout << "域名：" << domain_name << endl;
        cout << endl;
    }
    else
    {
        cout << "您输入的电子邮件地址不合法" << endl << endl;
    }

    return EXIT_SUCCESS;
} 