// Source : https://leetcode.com/problems/majority-element-ii/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 
 * ⌋ times. The algorithm should run in linear time and in O(1) space.
 * 
 *   How many majority elements could it possibly have?
 *   Do you have a better hint? Suggest it!
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        if (nums.empty())
            return vector<int>{};
        
        unordered_map<int,int> hash;

        for(const auto &num : nums) {
            hash[num]++;
            if (hash.size() >= 3) {
                auto it = hash.begin();
                while (it != hash.end() ) {
                    if (--(it->second) == 0) {
                        it = hash.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

        for(auto &kv : hash) {
            kv.second = 0;
        }
        for(const auto &num : nums) {
            if (hash.find(num) != hash.end()) {
                hash[num]++;
            }
        }

        vector<int> res;
        for(const auto &kv : hash) {
            if (kv.second > nums.size() / 3)
                res.emplace_back(kv.first);
        }
        return res;
    }
};
