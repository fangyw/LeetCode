// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Yuwei Fang
// Date   : 2015-08-31

/********************************************************************************** 
 * 
 * Given an array of integers, find if the array contains any duplicates. Your function 
 * should return true if any value appears at least twice in the array, and it should 
 * return false if every element is distinct.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/


class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> set;
        for(const auto &num : nums) {
            if (set.find(num) != set.end())
                return true;
            set.insert(num);
        }
        return false;
    }
};
