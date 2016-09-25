#pragma once

#include<vector>

class Kruskal
{
public:
    static std::vector<std::pair<int, int> > MinimumSpanningTree (int n
        , std::vector<std::pair<int/*weight*/, std::pair<int, int>/*edge*/ > > g);
};

