#include <iostream>
#include <string>
using namespace std;

int main()
{
 
    int n;
    cin >> n;
 
    int i, j;
    char arr[n][n + 1]; //需要存储 '\0' 所以列数为 n + 1
    for (i = 0; i < n; i++)
    {
        //arr[i] 表示第 i 行的数组名，即第 i 行的起始地址
        cin >> a[i];
    }
 
    //标记数组，memset 将 tmp 数组初始化为全0
    int tmp[n];
    memset(tmp, 0, n * sizeof(int));
 
    int count = 0;
    int ret = 0;
    for (i = 0; i < n; i++)
    {
        //该字符串已经确定出现的次数
        if (tmp[i] != 0)
            continue;
 
        //已经可以确定出现的最大次数
        if (ret >= n - i)
            break;
 
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            //arr[i] 表示第 i 行的字符串起始地址
            //未确定出现次数的字符串才进行比较
            if (tmp[j] == 0 && strcmp(arr[i], arr[j]) == 0)
            {
                count++;
                tmp[j] = 1;    //标记该字符串已经确定了出现的次数
            }
        }
 
        if (count > ret)
            ret = count;
    }
 
    cout << ret << endl;
    return 0;
}
 