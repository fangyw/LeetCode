// Source : https://leetcode.com/problems/count-complete-tree-nodes/
// Author : Yuwei Fang
// Date   : 2015-09-01

/********************************************************************************** 
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely 
 * filled, and all nodes in the last level are as far left as possible. It can have 
 * between 1 and 2h nodes inclusive at the last level h.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int height = treeHeight(root);
        int left = (1 << height) ;
        int right = (1 << (height+1)) - 1;

        // [left, right]
        // find the min left s.t. the node is not exist
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isExist(root, height, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
private:
    bool isExist(TreeNode* root, int height, int node_id) {
        int bit = (1 << height) >> 1;
        while (bit > 0) {
            if (node_id & bit) {
                root = root->right;
            } else {
                root = root->left;
            }
            bit >>= 1;
        }
        return root != nullptr;
    }

    int treeHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        while (root->left) {
            ++res;
            root = root->left;
        }
        return res;
    }
};

