// Source : https://leetcode.com/problems/maximal-square/
// Author : Yuwei Fang
// Date   : 2015-09-01

/********************************************************************************** 
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing 
 * all 1's and return its area.
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 4.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        // find the largest width of the square
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_width = 0;

        for(int i=0; i<n; ++i) {
            dp[0][i] = matrix[0][i] - '0'
            if (matrix[0][i] == '0')
                max_width = 1;
        }
        for(int i=1; i<m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            for(int j=1; j<n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                } else {
                    dp[i][j] = 0;
                }
                max_width = max(max_width, dp[i][j]);
            }
        }

        return max_width * max_width;
    }
};
