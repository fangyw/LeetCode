// Source : https://leetcode.com/problems/house-robber/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * You are a professional robber planning to rob houses along a street. Each house has 
 * a certain amount of money stashed, the only constraint stopping you from robbing 
 * each of them is that adjacent houses have security system connected and it will 
 * automatically contact the police if two adjacent houses were broken into on the same 
 * night.
 * 
 * Given a list of non-negative integers representing the amount of money of each 
 * house, determine the maximum amount of money you can rob tonight without alerting 
 * the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test 
 * cases. Also thanks to @ts for adding additional test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int rob(vector<int> &nums) {
        // dp[i] = max{dp[i-2]+nums[i], dp[i-1]}
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        const int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i=2; i<n; ++i) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

