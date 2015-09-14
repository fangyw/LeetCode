// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() -1;
        // find min left s.t. nums[left] < nums[left']
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution sol;
    vector<int> nums{4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << endl;
    return 0;
}

