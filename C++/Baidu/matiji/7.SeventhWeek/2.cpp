/*
 * @file    :2.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-15
 * @brief   :MT2115五彩斑斓的世界(栈)
 *          :符号匹配问题，利用栈来实现
 *          :匹配方法使用递归解决
 */
#include <iostream>

using namespace std;

int handle(){
    int res = 0;
    while(true){
        char c = getchar();
        if(c == '\n' || c == EOF)
            break;
        else if(c == 'a')
            res++;
        else if( c == '|')
            return max(res, handle());
        else if(c == '(')
            res += handle();
        else if(c == ')')
            return res;
        else
            continue;
    }
    return res;
}

int main()
{
    cout << handle() << endl;
    return 0;
}
