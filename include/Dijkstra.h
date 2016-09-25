#pragma once

#include <vector>

class Dijkstra
{
public:
    Dijkstra(int n, std::vector<std::vector<std::pair<int/*to*/, int/*weight*/> > > g);
    void Start(int s);
    int Distance(int to) const;
    std::vector<int> ShortestPath(int to) const;
private:
    int m_n;
    int m_s;
    std::vector<std::vector<std::pair<int/*to*/, int/*weight*/> > > m_g;
    std::vector<int> m_d;
    std::vector<int> m_p;
    std::vector<char> m_vis;
};