// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : Yuwei Fang
// Date   : 2015-09-07

/********************************************************************************** 
 * 
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement 
 * both?
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListRecu(head);
    }
private:
    ListNode* reverseListRecu(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* head2 = reverseListRecu(head->next);
        head->next->next = head;
        head->next = nullptr;
        return head2;
    }
    ListNode* reverseListNoRecu(ListNode* head) {
        // head insert
        ListNode dummy(-1);

        while (head) {
            ListNode* tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }
};

