#pragma once

#include <vector>
#include <string>

std::vector<int> prefSuff(const std::string& word);
    
std::vector<int> kmp(const std::string& text, const std::string& word)
{
    std::vector<int> match;
    std::vector<int> h = prefSuff(word);
    int n = text.length();
    int m = word.length();
    int i = 0, j = 0;
    while(i < n)
    {
        if (text[i] == word[j])
        {
            i++, j++;
        }
        if (j == m)
        {
            match.push_back(i - j);
            j = h[j - 1];
        }
        else if (i < n && text[i] != word[j])
        {
            if (j != 0)
                j = h[j - 1];
            else
                i++;
        }
   
    }
    return match;
    
}

std::vector<int> prefSuff(const std::string& word)
{
    std::vector<int> h(word.length(), 0);
    int i = 1, j = 0;
    while( i < word.length())
    {
        if (word[i] == word[j])
        {
            h[i] = j + 1;
            i++, j++;
        }
        else if (j == 0)
        {
            h[i] = 0;
            i++;
        }
        else
        {
            j = h[j - 1];
        }
    }
    return h;
}