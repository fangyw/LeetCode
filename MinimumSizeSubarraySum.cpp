// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : Yuwei Fang
// Date   : 2015-09-07

/********************************************************************************** 
 * 
 * Given an array of n positive integers and a positive integer s, find the minimal 
 * length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of which the 
 * time complexity is O(n log n).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int start=0, min_len = INT_MAX;

        int sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum >= s) {
                while (sum - nums[start] >= s) {
                    sum -= nums[start++];
                }
                min_len = min(min_len, i-start+1);
            }
        }
        return min_len;
    }
};

