#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(10);
    s.insert(1);
    s.insert(1);
    s.insert(12);
    s.insert(3);
    for (auto i : s)
    {
        cout << i << endl;
    }
    return 0;
}