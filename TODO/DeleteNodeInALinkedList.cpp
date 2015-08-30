// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Write a function to delete a node (except the tail) in a singly linked list, given 
 * only access to that node.
 * 
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with 
 * value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next != NULL) {
            node->val = node->next->val;
            ListNode* tmp = node->next->next;
            delete node->next;
            node->next = nullptr;
            node->next = tmp;
        } else {
            delete node;
            node = nullptr;
        }
    }
};



