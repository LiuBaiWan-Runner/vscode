/*
* @file    :3.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-04-01
* @brief   :设有n个正整数 (n<=20), 将它们连接成一排, 组成一个最大的多位整数
*          :https://blog.csdn.net/cckevincyh/article/details/78230430
*          :
*/
#include<iostream>
#include<string>
using namespace std;
bool compare(string a,string b)
{
    if(a+b>=b+a)//ab>=ba,这个时候不需要交换
    {
        return false;
    }
    return true;//ab<ba,这个时候需要交换
}

int main()
{
    int n;
    cin>>n;
    string arr[20],temp;

    for(int a=0;a<n;a++)
    {
        cin>>arr[a];
    }


    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(compare(arr[j-1],arr[j]))    //如果为true则交换,
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    for(int k=0;k<n;k++){
        cout<<arr[k];
    }
    cout<<endl;
    return 0;
}