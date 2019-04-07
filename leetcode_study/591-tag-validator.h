#pragma once

#include <string>
#include <stack>
using namespace std;

// Tag Validator
class Solution {
public:
    bool isValid(string code) {
        if (code.empty() || code[0] != '<') return false;

        std::stack<string> tagStack;

        size_t pos = 0;
        while (pos < code.length())
        {
            // if find a start tag, push to stack
            size_t endPos = code.find_first_of('>', pos);
            if (endPos == std::string::npos)
                return false;
            string tagName = code.substr(pos + 1, endPos - pos - 1);
            tagStack.push(tagName);

            // if find a end tag
        }
    }
};
