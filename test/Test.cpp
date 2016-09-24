#include "MergeSort.h"
#include "QuickSort.h"
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
