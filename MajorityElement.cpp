// Source : https://leetcode.com/problems/majority-element/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Given an array of size n, find the majority element. The majority element is the 
 * element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in 
 * the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.empty())
            return INT_MIN;
        int major = nums[0];
        int cnt = 1;

        for(int i=1; i<nums.size(); ++i) {
            if (nums[i] != major) {
                --cnt;
            } else {
                ++cnt;
            }
            if (cnt == 0) {
                major = nums[i];
                cnt = 1;
            }
        }
        return major;
    }
};

