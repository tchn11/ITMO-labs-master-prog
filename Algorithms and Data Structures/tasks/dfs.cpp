#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<int>& color, const vector<vector<int>>& graph) 
{
    for (int v : graph[u]) 
    {
        if (color[v] == 0) 
        {
            color[v] = -color[u];
            if (!dfs(v, color, graph)) 
                return false;
        } 
        else if (color[v] == color[u]) 
            return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> color(n + 1, 0);
    bool is_bipartite = true;
    
    for (int start = 1; start <= n && is_bipartite; ++start) 
    {
        if (color[start] == 0) 
        {
            color[start] = 1;
            if (!dfs(start, color, graph)) 
            {
                is_bipartite = false;
            }
        }
    }
    
    cout << (is_bipartite ? "YES" : "NO");
    return 0;
}