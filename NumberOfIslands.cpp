// Source : https://leetcode.com/problems/number-of-islands/
// Author : Yuwei Fang
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An 
 * island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are all 
 * surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty())
            return 0;
        // We shouldn't modify grid, so we must use visited to indicate whether we visit a grid or not.
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if (dfs(i,j,grid,visited))
                    ++cnt;
            }
        }
        return cnt;
    }
private:
    bool dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        if (grid[i][j] == '0' || visited[i][j])
            return false;
        // grid[i][j] == '1'
        visited[i][j] = true;
        vector<pair<int,int>> directions{{-1,0}, {1,0}, {0,1}, {0,-1}};
        for(int k=0; k<directions.size(); ++k) {
            int xi = directions[k].first + i;
            int yj = directions[k].second + j;
            dfs(xi, yj, grid, visited);
        }
        return true;
    }
};

