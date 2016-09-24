#include "MergeSort.h"
#include "QuickSort.h"
#include "BinarySearch.h"
#include "gtest/gtest.h"

#include <vector>

TEST(MergeSort, MergeSort)
{ 
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    MergeSort(arr.data(), arr.size());
    ASSERT_EQ(std::vector<int>({3, 9, 10, 27, 38, 43, 82}), arr);
}
 
TEST (QuickSort, QuickSort)
{ 
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    QuickSort(arr.data(), arr.size());
    ASSERT_EQ(std::vector<int>({3, 9, 10, 27, 38, 43, 82}), arr);
}

TEST (BinarySearch, BinarySearch)
{ 
    std::vector<int> arr = {3, 9, 10, 27, 38, 43, 82};
    
    ASSERT_EQ(0, BinarySearch(arr.data(), arr.size(), 3));
    ASSERT_EQ(2, BinarySearch(arr.data(), arr.size(), 10));
    ASSERT_EQ(5, BinarySearch(arr.data(), arr.size(), 43));
    ASSERT_EQ(6, BinarySearch(arr.data(), arr.size(), 82));
    ASSERT_EQ(-1, BinarySearch(arr.data(), arr.size(), 72));
    ASSERT_EQ(-1, BinarySearch(arr.data(), arr.size(), 0));
}