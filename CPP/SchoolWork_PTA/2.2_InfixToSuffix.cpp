#include <stdio.h>
#include<stdlib.h>
struct S
{
 char *data;
 int top;
 int maxsize;
};
typedef struct S * Stack;
void push(Stack S, char c);
char pop(Stack S);
int main()
{
	Stack St;
 	St = (Stack)malloc(sizeof(struct S));
	St->data = (char *)malloc(21 * sizeof(char));
 	St->top = -1;
	St->maxsize = 21;
 	char a[40];
	char c;
 	int i = 0;
 	while ((a[i++] = getchar()) != '\n'); //读入数据 换行终止
 	a[i] = '\0';
 	i = 0;
 	int flag = 1; //为了保证数字连续输入时，可以连续输出，例如输入123，输出123，而不是1 2 3
 	while (a[i] != '\0')
 	{
 		if (a[i] >= '0'&&a[i] <= '9')
  		{
   			if (flag == 1)
            {
                printf("%c", a[i]);
            }
   			else 
            {
                printf(" %c", a[i]); flag = 1;
            }
  		}
  		else if (a[i] == '.') //考虑运算数为非整数的情况
  		{
   			printf("%c", a[i]);
   			i++;
   			while (a[i] >= '0'&&a[i] <= '9')
   			{
    		    printf("%c", a[i]);
   				i++;
   			}
   			i--;
  		}
        else if (a[i] == '+')
        {
            if (i != 0); //第一个输入字符为+ 
            {
                if (St->top != -1 && St->data[St->top] != '(')
                {
                    while (St->top != -1 && St->data[St->top] != '(')
                    {
                        c = pop(St);
                        printf(" %c", c);
                    }
                }
                push(St, a[i]);
                flag = 0;
            }
        }
        else if (a[i] == '-')
        {
            if (i == 0)//第一个输入字符为-
            {
            printf("%c", a[i]);
            } 
            else
            {
                if (St->top != -1 && St->data[St->top] != '(')
                {
                    while (St->top != -1 && St->data[St->top] != '(')
                    {
                        c = pop(St);
                        printf(" %c", c);
                    }
                }
                push(St, a[i]);
                flag = 0;
            }
        }
        else if (a[i] == '*')
        {
            if (St->top != -1 && (St->data[St->top] == '*' || St->data[St->top] == '/'))
            {
                while (St->top != -1 && (St->data[St->top] == '*' || St->data[St->top] == '/'))
                {
                    c = pop(St);
                    printf(" %c", c);
                }
            }
            push(St, a[i]);
            flag = 0;
        }
        else if (a[i] == '/')
        {
            if (St->top != -1 && (St->data[St->top] == '*' || St->data[St->top] == '/'))
            {
                while (St->top != -1 && (St->data[St->top] == '*' || St->data[St->top] == '/'))
                {
                    c = pop(St);
                    printf(" %c", c);
                }
            }
            push(St, a[i]);
            flag = 0;
        }
        else if (a[i] == '(')
        {
            push(St, a[i]);
            if (a[i + 1] == '+')//像(+5)的情况
            {
                i++;
            } 
            else if (a[i + 1] == '-')//像(-5)的情况
            {
                printf(" %c", a[i + 1]);
                flag = 1;
                i++;
            } 
        }
        else if (a[i] == ')')
        {
            while (St->data[St->top] != '(')
            {
                c = pop(St);
                printf(" %c", c);
            }
            c = pop(St);
        }
        i++;
    }
    if (St->top != -1) //全部遍历后判断堆栈是否为空，不为空弹出栈内所有运算符
    {
        while (St->top != -1)
        {
            c = pop(St);
            printf(" %c", c);
        }
    }
    return 0;
}

//压栈
void push(Stack S, char c)
{
    S->top++;
    S->data[S->top] = c;
}

//出栈
char pop(Stack S)
{
    return S->data[S->top--];
}