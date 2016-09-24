#pragma once

int BinarySearch(int a[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            return BinarySearch(a, l, mid - 1, x);
        }
        return BinarySearch(a, mid + 1, r, x);
    }
    // Not Found
    return -1;
}

int BinarySearch(int a[], int sz, int x)
{
    return BinarySearch(a, 0, sz - 1, x);
}
