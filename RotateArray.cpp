// Source : https://leetcode.com/problems/rotate-array/
// Author : Yuwei Fang
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to 
 * [5,6,7,1,2,3,4]. 
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to 
 * solve this problem.
 * 
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * 
 * Related problem: Reverse Words in a String II
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
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
            return;
        const int n = nums.size();       
        k %= n;
        reverse(nums.begin(), next(nums.begin(), n-k));
        reverse(next(nums.begin(), n-k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

