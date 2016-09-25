#pragma once

#include <vector>
#include <stack>

int LagestRectangularAreaInHistogram(std::vector<int> hist)
{
    std::stack<int> st;
    int maxArea = 0;
    
    int i = 0;
    while (i < hist.size())
    {
        if (st.empty()
            || hist[i] > hist[st.top()])
        {
            st.push(i++);
        }
        else
        {
            int smaller = st.top();
            st.pop();
             
            int area = hist[smaller] * (st.empty() ? i : i - st.top() - 1);
            
            if (area > maxArea)
                maxArea = area;
        }
    }
    
    while (!st.empty())
    {
        int smaller = st.top();
        st.pop();
        int area = hist[smaller] * (st.empty() ? hist.size()
            : hist.size() - st.top() - 1);
        
        if (area > maxArea)
            maxArea = area;
    }
    
    return maxArea;
}

