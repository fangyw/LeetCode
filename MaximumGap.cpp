// Source : https://leetcode.com/problems/maximum-gap/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Given an unsorted array, find the maximum difference between the successive elements 
 * in its sorted form.
 * 
 * Try to solve it in linear time/space.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * You may assume all elements in the array are non-negative integers and fit in the 
 * 32-bit signed integer range.
 * 
 * Credits:Special thanks to @porker2008 for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        int bucket_size = (max_val - min_val) / nums.size() + 1;
        vector<vector<int>> buckets((max_val-min_val)/bucket_size + 1);

        for(int i=0; i<nums.size(); ++i) {
            int idx = (nums[i] - min_val) / bucket_size;
            if (buckets[idx].empty()) {
                buckets[idx].push_back(nums[i]);
                buckets[idx].push_back(nums[i]);
            } else {
                buckets[idx][0] = min(buckets[idx][0], nums[i]);
                buckets[idx][1] = max(buckets[idx][1], nums[i]);
            }
        }

        int res = 0;
        int prev = 0;
        for(int i=1; i<buckets.size(); ++i) {
            if (buckets[i].empty())
                continue;
            res = max(res, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return res;
    }
};

