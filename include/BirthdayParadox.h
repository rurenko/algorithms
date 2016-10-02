#pragma once

double TwoPeopleWithSameBirthdayProbability(int n)
{
    const double dayInYear = 365;
    long double prob = 1;
    for (int i = 1; i < n; ++i)
        prob *= 1 - i / dayInYear;
    return 1 - prob;
}

