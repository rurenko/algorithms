#include "MergeSort.h"
#include "QuickSort.h"
#include "BinarySearch.h"
#include "BFS.h"
#include "DFS.h"
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