#pragma once

#include <vector>


class TopologicalSort
{
public:
    static std::vector<int> Sort(int n, std::vector<std::vector<int> > g);
private:
    static void dfs(int v);
 
    static std::vector<std::vector<int> > m_g;
    static std::vector<int> m_res;
    static std::vector<char> m_vis;

};