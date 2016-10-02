#include "MergeSort.h"
#include "QuickSort.h"
#include "BinarySearch.h"
#include "BFS.h"
#include "DFS.h"
#include "TopologicalSort.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "LagestRectangularAreaInHistogram.h"
#include "KMP.h"
#include "RevertLinkedList.h"
#include "Euclid.h"
#include "Eratosthen.h"
#include "SumLinkedList.h"
#include "BirthdayParadox.h"
#include "Fibonacci.h"
#include "BellmanFord.h"
#include "gtest/gtest.h"

#include <vector>

TEST(Algorithm, MergeSort)
{ 
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    MergeSort(arr.data(), arr.size());
    ASSERT_EQ(std::vector<int>({3, 9, 10, 27, 38, 43, 82}), arr);
}
 
TEST(Algorithm, QuickSort)
{ 
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    QuickSort(arr.data(), arr.size());
    ASSERT_EQ(std::vector<int>({3, 9, 10, 27, 38, 43, 82}), arr);
}

TEST(Algorithm, BinarySearch)
{ 
    std::vector<int> arr = {3, 9, 10, 27, 38, 43, 82};
    
    ASSERT_EQ(0, BinarySearch(arr.data(), arr.size(), 3));
    ASSERT_EQ(2, BinarySearch(arr.data(), arr.size(), 10));
    ASSERT_EQ(5, BinarySearch(arr.data(), arr.size(), 43));
    ASSERT_EQ(6, BinarySearch(arr.data(), arr.size(), 82));
    ASSERT_EQ(-1, BinarySearch(arr.data(), arr.size(), 72));
    ASSERT_EQ(-1, BinarySearch(arr.data(), arr.size(), 0));
}

TEST(Algorithm, BFS)
{
    /*
     1--2  4--6
     |  |_/|_/|
     0  3--5--7 
     */
    std::vector<std::vector<int>> g = {
        {1},
        {0, 2},
        {1, 3},
        {2, 4, 5},
        {3, 5, 6},
        {3, 4, 6, 7},
        {4, 5, 7},
        {5, 6}
    };
    
    ASSERT_EQ(std::vector<int>({0,1,2,3,4,5,6,7}), bfs(0, 8, g));
    ASSERT_EQ(std::vector<int>({2,1,3,0,4,5,6,7}), bfs(2, 8, g));
    ASSERT_EQ(std::vector<int>({4,3,5,6,2,7,1,0}), bfs(4, 8, g));
    ASSERT_EQ(std::vector<int>({7,5,6,3,4,2,1,0}), bfs(7, 8, g));
}

TEST(Algorithms, DFS)
{
    /*
     1--2  4--6
     |  |_/|_/|
     0  3--5--7 
     */
    std::vector<std::vector<int>> g = {
        {1},
        {0, 2},
        {1, 3},
        {2, 4, 5},
        {3, 5, 6},
        {3, 4, 6, 7},
        {4, 5, 7},
        {5, 6}
    };
    ASSERT_EQ(std::vector<int>({0,1,2,3,4,5,6,7}), DFS::dfs(0, 8, g));
    ASSERT_EQ(std::vector<int>({2,1,0,3,4,5,6,7}), DFS::dfs(2, 8, g));
    ASSERT_EQ(std::vector<int>({4,3,2,1,0,5,6,7}), DFS::dfs(4, 8, g));
    ASSERT_EQ(std::vector<int>({7,5,3,2,1,0,4,6}), DFS::dfs(7, 8, g));
}

TEST(Algorithms, TopologicalSort)
{
    std::vector<std::vector<int>> g = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    }; 
    
    ASSERT_EQ(std::vector<int>({5,4,2,3,1,0}), TopologicalSort::Sort(6, g));
}

TEST(Algorithms, Kruskal)
{
    std::vector<std::pair<int, std::pair<int,int> > > g = {
        {4, {0, 1}},
        {8, {0, 7}},
        {11, {1, 7}},
        {8, {1, 2}},
        {7, {7, 8}},
        {1, {6, 7}},
        {2, {2, 8}},
        {6, {6, 8}},
        {7, {2, 3}},
        {4, {2, 5}},
        {2, {5, 6}},
        {14, {3, 5}},
        {9, {3, 4}},
        {10, {4, 5}}
    };
    
    std::vector<std::pair<int, int> > mst = {
        {6, 7},
        {2, 8},
        {5, 6},
        {0, 1},
        {2, 5},
        {2, 3},
        {0, 7},
        {3, 4} };
    
    ASSERT_EQ(mst, Kruskal::MinimumSpanningTree(9, g));
}

TEST(Algorithms, Dijkstra)
{
    std::vector<std::vector<std::pair<int,int> > > g = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {7, 11}, {2, 8}},
        {{1, 8}, {8, 2}, {5, 4}, {3, 7}},
        {{2, 7}, {5, 14}, {4, 9}},
        {{3, 9}, {5, 10}},
        {{6, 2}, {2, 4}, {3, 14}, {4, 10}},
        {{7, 1}, {8, 6}, {5, 2}},
        {{0, 8}, {1, 11}, {8,7}, {6, 1}},
        {{2, 2}, {6, 6}, {7,7}}
    };
    
    Dijkstra dijkstra(9, g);
    dijkstra.Start(0);
    
    ASSERT_EQ(0, dijkstra.Distance(0));
    ASSERT_EQ(4, dijkstra.Distance(1));
    ASSERT_EQ(12, dijkstra.Distance(2));
    ASSERT_EQ(19, dijkstra.Distance(3));
    ASSERT_EQ(21, dijkstra.Distance(4));
    ASSERT_EQ(11, dijkstra.Distance(5));
    ASSERT_EQ(9, dijkstra.Distance(6));
    ASSERT_EQ(8, dijkstra.Distance(7));
    ASSERT_EQ(14, dijkstra.Distance(8));
    
    ASSERT_EQ(std::vector<int>({}), dijkstra.ShortestPath(0));
    ASSERT_EQ(std::vector<int>({1, 2, 3}), dijkstra.ShortestPath(3));
    ASSERT_EQ(std::vector<int>({1, 2, 8}), dijkstra.ShortestPath(8));
    ASSERT_EQ(std::vector<int>({7, 6, 5, 4}), dijkstra.ShortestPath(4));
}

TEST(Algorithms, LagestRectangularAreaInHistogram)
{
    ASSERT_EQ(12, LagestRectangularAreaInHistogram({6, 2, 5, 4, 5, 1, 6}));
    ASSERT_EQ(4, LagestRectangularAreaInHistogram({1, 2, 3}));
    ASSERT_EQ(4, LagestRectangularAreaInHistogram({3, 2, 1}));
    ASSERT_EQ(3, LagestRectangularAreaInHistogram({3, 1, 2}));
}

TEST(Algorithms, KMP)
{
    ASSERT_EQ(std::vector<int>({0,1,0,1,2,3,4,5,2}), prefSuff("aabaabaaa"));
    ASSERT_EQ(std::vector<int>({}), kmp("AAAAAAA", "AAAB"));
    ASSERT_EQ(std::vector<int>({0}), kmp("THIS IS A TEST TEXT", "THIS"));
    ASSERT_EQ(std::vector<int>({10}), kmp("THIS IS A TEST TEXT", "TEST"));
    ASSERT_EQ(std::vector<int>({15}), kmp("THIS IS A TEST TEXT", "TEXT"));
    ASSERT_EQ(std::vector<int>({0, 9, 13}), kmp("AABAACAADAABAAABAA", "AABA"));
}

TEST(Algorithms, RevertLinkedList)
{
    Seq head;
    head.value = 1;
    head.AddNext(2)->AddNext(3)->AddNext(4)->AddNext(5)->AddNext(6);
    ASSERT_EQ(std::string("1->2->3->4->5->6"), PrintLinkedList(&head));
    Seq* rhead = RevertLinkedList(&head);
    ASSERT_EQ(std::string("6->5->4->3->2->1"), PrintLinkedList(rhead));
}


TEST(Algorithms, Euclid)
{
    ASSERT_EQ(25, Euclid(225, 800));
    ASSERT_EQ(1, Euclid(13, 7));
    ASSERT_EQ(9, Euclid(81, 36));
    ASSERT_EQ(100, Euclid(200, 500));
}

TEST(Algorithms, ExtendedEuclid)
{
    int d, x, y;
    int a = 81, b = 36;
    ExtendedEuclid(a, b, d, x, y);
    ASSERT_EQ(9, d);
    ASSERT_EQ(a * x + b * y, d);
    ASSERT_EQ(1, x);
    ASSERT_EQ(-2, y);
}

TEST(Algorithms, LeastCommonMultiplier)
{
    ASSERT_EQ(324, LeastCommonMultiplier(81, 36));
}

TEST(Algorithms, Eratosthen)
{
    ASSERT_EQ(std::vector<int>({2,3,5,7,11,13,17,19,23,29,31,37,41,
            43,47,53,59,61,67,71,73,79,83,89,97}), Eratosthen(100));
}

TEST(Algorithms, SumLinkedList)
{
    Seq first;
    first.value = 1;
    first.AddNext(0)->AddNext(9)->AddNext(4)->AddNext(6)->AddNext(2);
    Seq second;
    second.value = 8;
    second.AddNext(5)->AddNext(9);
    ASSERT_EQ(6, first.Size());
    ASSERT_EQ(3, second.Size());

    Seq* sum;
    sum = SumTwoList(&first, &second);
    ASSERT_EQ(std::string("1->1->0->3->2->1"), PrintLinkedList(sum));
}

TEST(Algorithms, BirthdayParadox)
{
    ASSERT_GT(TwoPeopleWithSameBirthdayProbability(23), 0.5);
}

TEST(Algorithms, Fibonacci)
{
    ASSERT_EQ(0, Fibonacci(0));
    ASSERT_EQ(1, Fibonacci(1));
    ASSERT_EQ(1, Fibonacci(2));
    ASSERT_EQ(2, Fibonacci(3));
    ASSERT_EQ(3, Fibonacci(4));
    ASSERT_EQ(5, Fibonacci(5));
    ASSERT_EQ(34, Fibonacci(9));
    ASSERT_EQ(4181, Fibonacci(19));
    ASSERT_EQ(5702887, Fibonacci(34));
}

TEST(Algorithms, BellmanFord)
{
    std::vector<Edge> g = {
        {0, 1, -1},
        {1, 2, 3},
        {0, 2, 4},
        {3, 2, 5},
        {1, 3, 2},
        {3, 1, 1},
        {1, 4, 2},
        {4, 3, -3}
    };
    ASSERT_EQ(std::vector<int>({0, -1, 2, -2, 1}), BellmanFord(g, 5, 0));
}