// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
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


// No.2: Add Two Numbers
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retList = NULL;
        ListNode* tail = NULL;
        int jinwei = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int tmp = jinwei + l1->val + l2->val;
            int curNum = tmp % 10;
            jinwei = (tmp - curNum) / 10;
            if (retList == NULL)
            {
                retList = new ListNode(curNum);
                tail = retList;
            }
            else
            {
                tail->next = new ListNode(curNum);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* remainList = (l1 != NULL) ? l1 : l2;
        while (remainList != NULL)
        {
            int tmp = jinwei + remainList->val;
            int curNum = tmp % 10;
            jinwei = (tmp - curNum) / 10;

            tail->next = new ListNode(curNum);
            tail = tail->next;

            remainList = remainList->next;
        }

        if (jinwei > 0)
        {
            tail->next = new ListNode(jinwei);
            tail = tail->next;
        }

        return retList;
    }
};




int main()
{
    Solution sl;
    sl.addTwoNumbers(NULL, NULL);
}
