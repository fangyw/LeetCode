// Source : https://leetcode.com/problems/largest-number/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * Given a list of non negative integers, arrange them such that they form the largest 
 * number.
 * 
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * 
 * Note: The result may be very large, so you need to return a string instead of an 
 * integer.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int a, const int b){
                return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        ostringstream oss;
        for(const auto &val : nums) {
            oss << val;
        }
        string res = oss.str();
        if (res[0] == '0')
            res = "0";
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums{3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << endl;
}
