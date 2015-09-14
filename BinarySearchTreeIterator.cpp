// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * Implement an iterator over a binary search tree (BST). Your iterator will be 
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 * where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/

class BSTIterator{
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> stk;
        pos = 0;
        while(!stk.empty() || root) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                elem.push_back(root->val);
                root = root->right;
            }
        }
    }

    bool hasNext() {
        return pos < elem.size();
    }

    int next() {
        return elem[pos++];
    }
private:
    vector<int> elem;
    int pos;
};

