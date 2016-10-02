#pragma once

#include <vector>
#include <cmath>

std::vector<int> Eratosthen(int n)
{
    std::vector<int> primes;
    std::vector<char> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i] == true)
            primes.push_back(i);
    }
    return primes;
}
