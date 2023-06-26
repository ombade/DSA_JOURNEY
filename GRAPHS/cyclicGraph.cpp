#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
bool dfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis, int node, int parent)
{
    vis[node] = 1;
    for (int i : adj[node])
        if ((vis[i] && i != parent) || (!vis[i] && dfs(adj, vis, i, node)))
            return 1;
    return 0;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> vis;

    // Create a adjacency list

    for (int i = 0; i < m; i++)
        adj[edges[i][0]].insert(edges[i][1]), 
        adj[edges[i][1]].insert(edges[i][0]);

    // Traverse over all vertices and check for cyclic BFS

    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(adj, vis, i, -1))
            return "Yes";
    return "No";
}
