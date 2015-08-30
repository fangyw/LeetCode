// Source : https://leetcode.com/problems/sliding-window-maximum/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given an array nums, there is a sliding window of size k which is moving from the 
 * very left of the array to the very right. You can only see the k numbers in the 
 * window. Each time the sliding window moves right by one position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty 
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 *   How about using a data structure such as deque (double-ended queue)?
 *   The queue size need not be the same as the window’s size.
 *   Remove redundant elements and the queue should store only elements that need to be 
 * considered.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        
        if (k == 0 || nums.empty())
            return res;
        for(int i=0; i<nums.size(); ++i) {
            while (!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
            while (i-deq.front() >= k)
                deq.pop_front();
            
            if (i >= k-1) {
                res.emplace_back(nums[deq.front()]);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int, greater<int>> bst;
        
        if (nums.empty() || k == 0)
            return res;
        
        for(int i=0; i<nums.size(); ++i) {
            bst.insert(nums[i]);
            if (bst.size() > k) {
                bst.erase(bst.find(nums[i-k]));
            }
            if (i >= k-1)
                res.emplace_back(*bst.begin());
        }
        return res;
    }
};