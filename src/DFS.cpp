#include "DFS.h"

std::vector<char> DFS::m_vis;
std::vector<std::vector<int>> DFS::m_g;
std::vector<int> DFS::m_res;

std::vector<int> DFS::dfs(int s, int n, std::vector<std::vector<int>> g)
{
    m_g = g;
    m_vis = std::vector<char>(n);
    m_res.clear();
    _dfs(s);
    return m_res;
}

void DFS::_dfs(int v)
{
    m_res.push_back(v);
    m_vis[v] = true;
    for(const auto& u: m_g[v])
    {
        if (!m_vis[u])
        {
            _dfs(u);
        }
    }
    
}

