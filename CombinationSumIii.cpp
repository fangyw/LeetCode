// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Yuwei Fang
// Date   : 2015-09-01

/********************************************************************************** 
 * 
 * Find all possible combinations of k numbers that add up to a number n, given that 
 * only numbers from 1 to 9 can be used and each combination should be a unique set of 
 * numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 * 
 *  Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 *  Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
       
        int cur_sum = 0;

        dfs(cur_sum,1,k,n,path,res);
        return res;
    }

private:
    void dfs(int sum, int start, int k, int n, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == k && sum == n) {
            res.emplace_back(path);
            return;
        }

        for(int i=start; i<=9; ++i) {
            if (sum + i > n)
                break;
            path.emplace_back(i);
            dfs(sum+i,i+1,k,n,path,res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(3,9);
    for(const auto &row : ans) {
        for(const auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
