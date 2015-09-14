// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Follow up for "Find Minimum in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() -1;
        // find min left s.t. nums[left] < nums[left']
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else if (nums[mid] > nums[left]){
                left = mid + 1;
            } else {
                ++left;
            }
        }
        return nums[left];
    }
};
