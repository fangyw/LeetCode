// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : Yuwei Fang
// Date   : 2015-09-08

/********************************************************************************** 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);

        ListNode* prev = &dummy;
        while (head) {
            if (head->val != val) {
                prev->next = head;
                prev = prev->next;
                head = head->next;
            } else {
                ListNode* tmp = head->next;
                delete head;
                head = tmp;
            } 
        }
        prev->next = nullptr;
        return dummy.next;
    }
};

