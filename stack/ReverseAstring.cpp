#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string str1 = "ommmibade";
    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        s.push(ch);
    }

    string ans = "";
    while (!s.empty())
    {
        char c = s.top();
        // ans = ans + c;
        ans.push_back(c);
        s.pop();
    }
    cout << ans;
    return 0;
}