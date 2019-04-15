#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.length();
        unordered_map<unsigned char, int> cacheMap;
        for (int i = 0, j = 0; j < n; j++)
        {
            auto it = cacheMap.find(s[j]);
            if (it != cacheMap.end())
            {
                i = max(i, it->second + 1);
                it->second = j;  // update new position
            }
            else
            {
                cacheMap.insert(std::make_pair(s[j], j));
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
