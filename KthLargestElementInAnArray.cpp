// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Author : Yuwei Fang
// Date   : 2015-09-01

/********************************************************************************** 
 * 
 * Find the kth largest element in an unsorted array. Note that it is the kth largest 
 * element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty())
            return 0;
        int left = 0, right = nums.size()-1;
        default_random_engine gen((random_device())());

        while (left <= right) {
            uniform_int_distribution<int> dis(left,right);
            int pivot_idx = dis(gen);
            int new_pivot_idx = partitionByPivot(nums, pivot_idx, left, right);
            if (new_pivot_idx == k-1) {
                return nums[new_pivot_idx];
            } else if (new_pivot_idx > k-1) {
                right = new_pivot_idx-1;
            } else {
                left = new_pivot_idx + 1;
            }
        }
        return nums.back();
    }
private:
    int partitionByPivot(vector<int>&nums, int pivot_idx, int left, int right) {
        int pivot_val = nums[pivot_idx];
        int new_pivot_idx = left;

        swap(nums[pivot_idx], nums[right]);
        for(int i=left; i<right; ++i) {
            if (nums[i] > pivot_val) {
                swap(nums[new_pivot_idx++], nums[i]);
            }
        }
        swap(nums[right], nums[new_pivot_idx]);
        return new_pivot_idx;
    }
};

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty())
            return 0;
        nth_element(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
        return *next(nums.begin(), k);
    }
};
