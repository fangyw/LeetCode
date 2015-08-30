// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *               
 *               
 * 
 *               
 **********************************************************************************/


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        // step1: find the middle node
        
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        
        slow = reverseList(slow);
        return isEqual(head, slow);
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *cur = head, *prev = NULL;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    bool isEqual(ListNode* p, ListNode* q) {
        if (q == NULL)
            return true;
        if (p->val != q->val)
            return false;
        return isEqual(p->next, q->next);
    }
};

