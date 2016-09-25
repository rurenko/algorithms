#pragma once

#include <vector>

class DFS
{
public:
    static std::vector<int> dfs(int s, int n, std::vector<std::vector<int>> g);
private:
    static void _dfs(int v);
    static std::vector<std::vector<int> > m_g;
    static std::vector<char> m_vis;
    static std::vector<int> m_res;
};
