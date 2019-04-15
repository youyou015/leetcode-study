#pragma once

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 中心扩散法
        int maxLen = 0, n = s.length();
        int startIdx = 0;
        for (int i = 0; i < n; i++)
        {
            // 中心为一个元素
            int tmpLen = 1, j = 1;
            while (i - j >= 0 && i + j < n)
            {
                if (s[i - j] == s[i + j])
                {
                    tmpLen += 2;
                    j++;
                }
                else
                {
                    break;
                }
            }
            if (tmpLen > maxLen)
            {
                maxLen = tmpLen;
                startIdx = i - (tmpLen >> 1);
            }

            // 中心两个元素
            if (i != n -1 && s[i] == s[i+1])
            {
                tmpLen = 2, j = 1;
                while (i - j >= 0 && i + 1 + j < n)
                {
                    if (s[i - j] == s[i + 1 + j])
                    {
                        tmpLen += 2;
                        j++;
                    }
                    else break;
                }
                if (tmpLen > maxLen)
                {
                    maxLen = tmpLen;
                    startIdx = i - ((tmpLen - 1) >> 1);
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }

    static void main()
    {
        Solution sl;
        string s = "babad";
        cout << s << "\n" << sl.longestPalindrome(s) << endl;
    }
};
