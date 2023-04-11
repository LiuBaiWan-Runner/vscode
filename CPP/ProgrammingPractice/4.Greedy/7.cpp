https://blog.csdn.net/u013476556/article/details/38350403#:~:text=A%20prefix%20of%20a%20string%20is%20a%20substring,is%20considered%20to%20be%20a%20prefix%20of%20itself.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
 
using namespace std;
 
struct node
{
    int f;
    struct node *next[26];
};
 
struct node *build ()
{
    struct node *t;
    t = (struct node *)malloc(sizeof (struct node));
    for (int i = 0; i < 26; i++)
    {
        t -> next[i] = NULL;
    }
    t -> f = 0;
    return t;
}
 
void charu (struct node *t,char s[])
{
    int len = strlen (s);
    int ans;
    for (int i = 0; i < len ; i++)
    {
        ans = s[i] - 'a';
        if (t ->next[ans] == NULL)
        {
            t -> next[ans] = build ();
            t = t->next[ans];
            t -> f = 1;
        }
        else
        {
            t = t -> next[ans];
            t -> f++;
        }
    }
 
}
 
void findd (struct node *t,char s[])
{
    int len = strlen (s);
    int ans;
    for (int i = 0; i < len ; i++)
    {
        printf ("%c",s[i]);
        ans = s[i] - 'a';
        t = t -> next[ans];
        if (t -> f == 1)
            break;
 
    }
}
 
void del (struct node *t)
{
    for (int i =0 ; i < 26; i++)
    {
        if (t->next[i]!=NULL)
        {
            del (t->next[i]);
        }
    }
    free(t);
}
 
char a[100000][100];
 
int main ()
{
 
    int n = 0;
    struct node *tree ;
    tree = build ();
    while (~scanf ("%s",a[n]))
    {
        charu (tree,a[n]);
        n++;
    }
    for (int i = 0; i < n ; i++)
    {
        printf ("%s ",a[i]);
        findd (tree,a[i]);
        printf ("\n");
    }
   // del(tree);
    return 0;
}