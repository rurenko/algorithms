#pragma once

#include <vector>
#include <climits>

struct Edge
{
    int from;
    int to;
    int weight;
};

std::vector<int> BellmanFord(std::vector<Edge> g, int n, int s)
{
    std::vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < g.size(); ++j)
        {
            if (dist[g[j].from] < INT_MAX)
            {
                dist[g[j].to] = std::min(dist[g[j].to]
                        , dist[g[j].from] + g[j].weight);
            }
        }
    }
    return dist;
}

