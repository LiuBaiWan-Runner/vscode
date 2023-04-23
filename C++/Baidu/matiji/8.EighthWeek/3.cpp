/*
 * @file    :3.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-04-22
 * @brief   :Mt2114括号家族
 *          :
 *          :
 */
#include <iostream>
#include <stack>
using namespace std;
const int N = 1e6 + 7;

struct Node
{
    char c;
    int ID;
};
bool tag[N];
string str;
stack<Node> st;

int main()
{
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (!st.empty() && st.top().c == '(' && str[i] == ')')
        {
            tag[i] = tag[st.top().ID] = true;
            st.pop();
        }
        else
        {
            st.push({str[i], i});
        }
    }
    int maxlen = 0, tmp = 0, cnt = 0;
    for (int i = 0; i <= len; i++)
    {
        if (tag[i])
            tmp++;
        else{
            maxlen = max(maxlen, tmp);
            tmp = 0;
        }
    }
    for(int i = 0; i <= len; i++){
        if (tag[i])
            tmp++;
        else
        {
            if (tmp == maxlen)
                cnt++;
            tmp = 0;
        }
    }
    if (maxlen)
        cout << maxlen << " " << cnt << endl;
    else
        cout << "0 1" << endl;
    return 0;
}
