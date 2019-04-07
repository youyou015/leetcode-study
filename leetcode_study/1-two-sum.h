#pragma once

#include <unordered_map>
#include <vector>
using namespace std;


// No. 1: Two Sum
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = myMap.find(target - nums[i]);
        if (it != myMap.end())
        {
            vector<int> retVec = { it->second, i };
            return retVec;
        }
        myMap.insert(make_pair(nums[i], i));
    }
    return vector<int>();
}
