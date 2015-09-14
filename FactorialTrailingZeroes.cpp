// Source : https://leetcode.com/problems/factorial-trailing-zeroes/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int trailingZeroes(int n) {
        if (n <= 0)
            return 0;
        int res = 0;
        // 1,2,.., 11
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};

