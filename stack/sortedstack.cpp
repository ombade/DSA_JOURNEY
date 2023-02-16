#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> s, int n)
{
    if (s.empty() || (!s.empty() && s.top() < n))
    {
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    /// recusrive
    insert(s, n);
    s.push(n);
}
void sort1(stack<int> s)
{ // bstaase case conditon
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sort1(s);
    insert(s, num);
}
int main()
{
    stack<int> s;
    s.push(1);
    sort1(s);
}