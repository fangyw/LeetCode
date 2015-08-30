// Source : https://leetcode.com/problems/invert-binary-tree/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Invert a binary tree.
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t 
 * invert a binary tree on a whiteboard so fuck off.
 *               
 **********************************************************************************/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }
};

