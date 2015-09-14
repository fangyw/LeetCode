// Source : https://leetcode.com/problems/binary-tree-right-side-view/
// Author : Yuwei Fang
// Date   : 2015-09-09

/********************************************************************************** 
 * 
 * Given a binary tree, imagine yourself standing on the right side of it, return the 
 * values of the nodes you can see ordered from top to bottom.
 * 
 * For example:
 * Given the following binary tree,
 * 
 *    1            
 * 
 * You should return [1, 3, 4].
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        queue<TreeNode*> que[2];
        int level = 0;
        que[level%2].emplace(root);
        while (!que[level%2].empty()) {
            bool first = true;
            while (!que[level%2].empty()) {
                TreeNode* node = que[level%2].front();
                que[level%2].pop();
                if (first) {
                    res.emplace_back(node->val);
                    first = false;
                }
                if (node->right)
                    que[(level+1)%2].emplace(node->right);
                if (node->left)
                    que[(level+1)%2].emplace(node->left);
            }
            ++level;
        }

        return res;
    }
};

