// Source : https://leetcode.com/problems/shortest-palindrome/
// Author : Yuwei Fang
// Date   : 2015-09-01

/********************************************************************************** 
 * 
 * Given a string S, you are allowed to convert it to a palindrome by adding characters 
 * in front of it. Find and return the shortest palindrome you can find by performing 
 * this transformation.
 * 
 * For example: 
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all test 
 * cases. Thanks to @Freezen for additional test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

// aaceaaaa aaaecaaaaceaaa
// abcd dcbabcd
// find the longest palindrome in S'S
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public: 
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;
        string rev_s(s.rbegin(), s.rend());
        return findLongestPalindrome(std::move(rev_s + s), s.length());
    }
private:
    string findLongestPalindrome(const string& s, int len) {
        const int n = s.length();
        bool dp[n][n];
        memset(dp, 0, n*n);
        int res_start = n, res_len = 0;
        for(int i=n-1; i>=0; --i) {
            for(int j=i; j<n; ++j) {
                dp[i][j] = (s[i] == s[j] && ((j-i<2) || dp[i+1][j-1]));
            }
            if (dp[i][n-1] && n-i > len) {
                return s.substr(i);
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    string str("a");
    cout << sol.shortestPalindrome(str) << endl;
}
