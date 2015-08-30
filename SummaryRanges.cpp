// Source : https://leetcode.com/problems/summary-ranges/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.empty()) {
            return res;
        }

        int start = 0;
        nums.emplace_back(nums.back()-1);
        for(int i=1; i<nums.size(); ++i) {
            if (nums[i] != nums[i-1] + 1) {
                res.emplace_back(summary(nums,start,i));
                start = i;
            }
        }
        nums.pop_back();
        return res;
    }
private:
    string summary(const vector<int> &nums, int begin, int end) {
        ostringstream oss;
        oss << nums[begin++];
        if (begin != end)
            oss << "->" << nums[end-1];
        return oss.str();
    }

};

int main() {
    Solution sol;
    vector<int> nums{0,1,2,4};
    vector<string> output = sol.summaryRanges(nums);

    for(const auto &str : output)
        cout << str << endl;
}
