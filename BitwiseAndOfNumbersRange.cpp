// Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author : Yuwei Fang
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Given a range [m, n] where 0 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = 0xffffffff;
        while (mask != 0) {
            if ((m & mask) == (n & mask))
                break;
            mask <<= 1;
        }
        return m & mask;
    }
};

