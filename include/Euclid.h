#pragma once

int Euclid(int a, int b)
{
    if (a < b)
        std::swap(a, b);
    if (b == 0)
        return a;
    else
        return Euclid(b, a % b);
}

void ExtendedEuclid(int a, int b, int& d, int& x, int& y)
{
    if (a < b)
        std::swap(a, b);
    if (b == 0)
    {
        d = a, x = 1, y = 0;
        return;
    }
    else
    {
        int x_, y_;
        ExtendedEuclid(b, a % b, d, x_, y_);
        x = y_;
        y = x_ - (a / b) * y_; 
    }
}

int LeastCommonMultiplier (int a, int b)
{
	return a / Euclid (a, b) * b;
}