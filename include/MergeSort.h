#pragma once

#include <stddef.h>

void Merge(int a[], size_t l, size_t m, size_t r);

void MergeSort(int a[], size_t l, size_t r)
{
    if (l < r)
    {
        size_t m = (l + r) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m , r);
    }
}

void Merge(int a[], size_t l, size_t m, size_t r)
{
    size_t sizeLeft = m - l + 1;
    size_t sizeRight = r - m;
    int left[sizeLeft];
    int right[sizeRight];
    for (int i = 0; i < sizeLeft; ++i)
        left[i] = a[l + i];
    for (int i = 0; i < sizeRight; ++i)
        right[i] = a[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < sizeLeft && j < sizeRight)
    {
        if (left[i] < right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }
    while (i < sizeLeft)
        a[k++] = left[i++];

    while (j < sizeRight)
        a[k++] = right[j++];

}

void MergeSort(int a[], size_t sz)
{
    MergeSort(a, 0, sz - 1);
}