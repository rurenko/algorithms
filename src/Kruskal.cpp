#include "Kruskal.h"

#include<algorithm>   //sort

std::vector<std::pair<int, int> > Kruskal::MinimumSpanningTree(int n
    , std::vector<std::pair<int, std::pair<int, int> > > g)
{
   std::vector<std::pair<int, int> > res;
   std::vector<int> treeId (n);
   
   std::sort(g.begin(), g.end());
   
   for (int i = 0; i < n; ++i)
       treeId[i] = i;
   
   for (const auto& pair: g)
   {
       int a = pair.second.first;
       int b = pair.second.second;
       if (treeId[a] != treeId[b])
       {
           int treeIdNew = treeId[a];
           int treeIdOld = treeId[b];
           for (int i = 0; i < n; ++i)
           {
               if (treeId[i] == treeIdOld)
               {
                   treeId[i] = treeIdNew;
               }
           }
           res.push_back(std::make_pair(a, b));
       }
   }
   return res;
}

