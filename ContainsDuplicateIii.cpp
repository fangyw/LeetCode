// Source : https://leetcode.com/problems/contains-duplicate-iii/
// Author : Yuwei Fang
// Date   : 2015-08-31

/********************************************************************************** 
 * 
 * Given an array of integers, find out whether there are two distinct indices i and j 
 * in the array such that the difference between nums[i] and nums[j] is at most t and 
 * the difference between i and j is at most k.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || k <= 0)
            return false;

        multiset<int> bst;
        for(int i=0; i<nums.size(); ++i) {
            if (bst.size() > k) {
                bst.erase(bst.find(nums[i-k-1]));
            }
            auto it = bst.lower_bound(nums[i]-t);
            if (it != bst.end() && abs(*it - nums[i]) <= t)
                return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};

class Solution2 {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || k <= 0)
            return false;

        set<int> bst;
        int low = 0;
        for(int i=0; i<nums.size(); ++i) {
            if (i - low > k) {
                bst.erase(bst.find(nums[low]));
                ++low;
            }
            auto it = bst.lower_bound(nums[i]-t);
            if (it != bst.end() && abs(*it - nums[i]) <= t)
                return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};

