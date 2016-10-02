#pragma once

#include "RevertLinkedList.h"

void SumTwoEqLengthList(Seq* first, Seq* second, Seq*& sum, int& rem)
{
    if (first != nullptr && second != nullptr)
    {
        int lastRem;
        SumTwoEqLengthList(first->Next, second->Next, sum, lastRem);
        int value = first->value + second->value + lastRem;
        sum = Seq::AddFirst(sum, value % 10);
        rem = value / 10;
    }
    else
    {
        sum = nullptr;
        rem = 0;
    }
}

void SumSubAnswerAndRemind(Seq* begin, Seq* last, Seq* subAns, int subRem, Seq*& sum, int& rem)
{
    if (begin != last)
    {
        int lastRem;
        SumSubAnswerAndRemind(begin->Next, last, subAns, subRem, sum, lastRem);
        int value = begin->value + lastRem;
        sum = Seq::AddFirst(sum, value % 10);
        rem = value / 10;
    }
    else
    {
        sum = subAns;
        rem = subRem;
    }
}

Seq* SumTwoList(Seq* first, Seq* second)
{
    int firstSize = first->Size();
    int secondSize = second->Size();
    if (firstSize == secondSize)
    {
        Seq* ans;
        int remind;
        SumTwoEqLengthList(first, second, ans, remind);
        if (remind != 0)
        {
            ans = Seq::AddFirst(ans, remind);
        }
        return ans;
    }
    if (firstSize < secondSize)
    {
        std::swap(first, second);
    }
    int diffSize = abs(firstSize - secondSize);
    Seq* firstSubList = first;
    for (int i = diffSize; i > 0; --i)
    {
        firstSubList = firstSubList->Next;
    }
    Seq* subAns;
    int remind;
    SumTwoEqLengthList(firstSubList, second, subAns, remind);
    Seq* ans;
    int rem;
    SumSubAnswerAndRemind(first, firstSubList, subAns, remind, ans, rem);
    if (rem != 0)
    {
        ans = Seq::AddFirst(ans, rem);
    }
    return ans;
}