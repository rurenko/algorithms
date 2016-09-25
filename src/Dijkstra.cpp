#include "Dijkstra.h"
#include <climits>


Dijkstra::Dijkstra(int n, std::vector<std::vector<std::pair<int, int> > > g)
    : m_g(g), m_n(n)
{
    m_d.assign(n, INT_MAX);
    m_vis.assign(n, false);
    m_p.resize(n);
}

void Dijkstra::Start(int s)
{
    m_s = s;
    m_d[s] = 0;
    
    for (int i = 0; i < m_n; ++i)
    {
        int v = -1;
        for (int u = 0; u < m_n; ++u)
        {
            if (!m_vis[u] && (v == -1 || m_d[u] < m_d[v]))
            {
                v = u;
            }
        }
        
        if (m_d[v] == INT_MAX)
            return;

        m_vis[v] = true;

        for (int u = 0; u < m_g[v].size(); ++u)
        {
            int to = m_g[v][u].first;
            int weight = m_g[v][u].second;
            
            if ((m_d[v] + weight) < m_d[to])
            {
                m_d[to] = m_d[v] + weight;
                m_p[to] = v;
            }
        }
    }
}

int Dijkstra::Distance(int to) const
{
    return m_d.at(to);
}

std::vector<int> Dijkstra::ShortestPath(int to) const
{
    std::vector<int> path;
    for (int v = to; v != m_s; v = m_p[v])
    {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}



