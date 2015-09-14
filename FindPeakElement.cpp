// Source : https://leetcode.com/problems/find-peak-element/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its 
 * index.
 * 
 * The array may contain multiple peaks, in that case return the index to any one of 
 * the peaks is fine.
 * 
 * You may imagine that num[-1] = num[n] = -∞.
 * 
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should 
 * return the index number 2.
 * 
 * click to show spoilers.
 * 
 * Note:
 * Your solution should be in logarithmic complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid-1] < nums[mid]) && (mid == nums.size()-1 || nums[mid] > nums[mid+1])) {
                return mid;
            } else if (mid > 0 && nums[mid-1] > nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums{0};
    cout << sol.findPeakElement(nums);
}

