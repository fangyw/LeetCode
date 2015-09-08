// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Yuwei Fang
// Date   : 2015-08-31

/********************************************************************************** 
 * 
 * Given an array of integers and an integer k, find out whether there are two distinct 
 * indices i and j in the array such that nums[i] = nums[j] and the difference between 
 * i and j is at most k.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int,int> hash;

        for(int i=0; i<nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                if (i-hash[nums[i]] <= k)
                    return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};

