// Source : https://leetcode.com/problems/power-of-two/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n-1)) == 0;
    }
};
