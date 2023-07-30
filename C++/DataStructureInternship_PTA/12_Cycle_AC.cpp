/*
 * @file    :12_Cycle_AC.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-30
 * @brief   :Cycle
 *          :
 *          :
 */

//本题的逻辑结构：线性表
//本题的存储结构：顺序
//解题思路和算法：将字符串1和自身拼接成新字符串，用待匹配字符用kmp算法匹配目标串，如果成功匹配，则说明
                // 可以实现，否则说明不可实现
//效率:假设m为模式串的长度，n为待匹配的字符串的长度，时间复杂度为 O(m+n)、空间复杂度 O(1)：
//测试数据： （1）输入
// 4
// AACD CDAA
// ABCDEFG EFGABCD
// ABCD ACBD
// ABCDEFEG ABCDEE
// （2）输入
// 2
// ASDF FDAS
// ASDF SDFA
// 输出：
// NO
// YES

#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef int bool;
#define true 1
#define false 0
char* str1;
char* str2;
char* targetStr;
int next[1000];

typedef int Position;
typedef struct LNode * PtrToLNode;
struct LNode{
    char * Data;
};
typedef PtrToLNode List;

List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    return L;
}

void getNext(int next[],char* str2,int str2_len)
{
    memset(next,0,sizeof(next[1000]));
    next[0]=-1;
    for(int i=0,j=-1;i<str2_len;j++){
        if(j==-1||str2[i]==str2[j])
            next[++i]=j+1;
        else
            j=next[j];
            j--;
    }
        
}

int kmp(char str1[],char str2[],int next[])
{
    int str1_len=strlen(str1);
    int str2_len=strlen(str2);
    getNext(next,str2,str2_len);
    for(int i=0,j=0;i<strlen(str1);)
    {
        if(j==-1||str1[i]==str2[j])i++,j++;
        else
        j=next[j];
        if(j>=str2_len)
        return 1;
    }
    return 0;
}

int main()
{
    List L_target = MakeEmpty();
    L_target->Data = (char *)malloc(sizeof(char[1000]));

    List L1 = MakeEmpty();
    L1->Data = (char *)malloc(sizeof(char[1000])); 

    List L2 = MakeEmpty();
    L2->Data = (char *)malloc(sizeof(char[1000]));

    int str1_len;
    scanf("%d", &str1_len);
    for(int i=0;i<str1_len;i++)
    {
        scanf("%s %s",L1->Data,L2->Data);
        strcpy(L_target->Data,L1->Data);
        strcat(L_target->Data,L1->Data);

        if(strlen(L1->Data)==strlen(L2->Data) && kmp(L_target->Data,L2->Data,next))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
