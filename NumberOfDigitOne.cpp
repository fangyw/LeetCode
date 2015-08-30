// Source : https://leetcode.com/problems/number-of-digit-one/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given an integer n, count the total number of digit 1 appearing in all non-negative 
 * integers less than or equal to n.
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 *   Beware of overflow.
 * 
 * Analysis: Suppose n = abcde, we count the number of digit 1 appearing in c.               
 *           1. c == 0
 *              eg. 12034, 100,101,..,199,1100,1101,..,1199,2100,..,9199
 *              count = 1200
 *           2  c == 1
 *              eg. 12134, count = 1200 + 34 + 1
 *           3. c > 1
 *              eg. 12234, count = 1300
 * 
 *               
 **********************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        long long factor = 1;
        const int k = 1;

        while (n >= factor) {
            int cur_digit = (n / factor) % 10;
            int higher_digit = (n / factor) / 10;
            int lower_digit = n % factor;

            if (cur_digit < k) {
                count += higher_digit * factor;
            } else if (cur_digit == k) {
                count += higher_digit * factor + lower_digit + 1;
            } else {
                count += (higher_digit + 1) * factor;
            }
            factor *= 10;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums{12034, 12134, 12234};
    for(const auto &num : nums) {
        cout << sol.countDigitOne(num) << endl;
    }
    return 0;
}
