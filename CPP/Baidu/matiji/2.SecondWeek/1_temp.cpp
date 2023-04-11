/*
* @file    :1.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-09
* @brief   :位运算
*          :加减乘除
*          :https://blog.csdn.net/sinat_35261315/article/details/72904945
*/
#include <iostream>

using namespace std;

int add(int a, int b)
{
    return (b == 0) ? a : add(a ^ b, (a & b) << 1);
    /*
    if(b == 0)
        return a;
    else
        return add(a ^ b, (a & b) << 1);
        //异或结果 + 与运算结果左移一位
    */
}

/*
//求n的补码
//~：按位取反
//add：加法操作，末位加一
*/
int negtive(int n)
{
    return add(~n, 1);
}

int subtraction(int a, int b)
{
    //加上被减数的补码
    return add(a, negtive(b));
}


//对于四个字节即32位整型
//取出符号位
int getSign(int n)
{
    return n >> 31;
}

//求n的绝对值
int positive(int n)
{
    return (getSign(n) & 1) ? negtive(n) : n;
}

int multiply(int a, int b)
{
    //如果两个数符号位不相容，则结果为负
    bool isNegtive = false;
    if(getSign(a) ^ getSign(b))
        isNegtive = true;

    a = positive(a);
    b = positive(b);

    int res = 0;
    while(b | 0)
    {
        //当b的对应位是1时，才需要加a
        if(b & 1)
            res = add(res, a);
        a = a << 1; //a左移
        b = b >> 1; //b右移
    }

    return isNegtive == true ? negtive(res) : res;
}

int divide(int a, int b)
{
    //被除数不能为0
    if(b == 0)
        throw std::runtime_error("Divided can't be zero...");

    bool isNegtive = false;
    if(getSign(a) ^ getSign(b))
        isNegtive = true;

    a = positive(a);
    b = positive(b);

    int res = 0;
    while(a >= b)
    {
        res = add(res, 1);
        a = subtraction(a, b);
    }

    return beNegtive == true ? negtive(res) : res;
}


int main()
{
    
    return 0;
}
