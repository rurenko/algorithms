#pragma once

#include <vector>
#include <queue>
#include <iostream>

std::vector<int> bfs(int s, int n, std::vector<std::vector<int>> g)
{
    std::vector<int> res;

    std::queue<int> q;
    q.push(s);
    std::vector<bool> vis;
    vis.resize(n);
    vis[s] = true;
    
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        res.push_back(vertex);
        
        for (const auto& v : g[vertex])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return res;
}

