#pragma once

#include <random>
#include <iostream>

int GetRandom(int l, int r);

void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        std::swap(a[l], a[GetRandom(l,r)]);

        int k = l;
        for (int i = l + 1; i <= r; ++i)
        {
            if (a[i] < a[l])
            {
                std::swap(a[++k], a[i]);
            }
            
        }
        std::swap(a[l], a[k]);

        QuickSort(a, l, k - 1);
        QuickSort(a, k + 1, r);
    }
}

int GetRandom(int l, int r)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(l, r);
    int rnd = dist(mt);
    return rnd;
}


void QuickSort(int a[], int sz)
{
    QuickSort(a, 0, sz - 1);
}