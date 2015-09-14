// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Write a program to find the node at which the intersection of two singly linked 
 * lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = listLen(headA);
        int len2 = listLen(headB);

        ListNode* pa = headA, *pb = headB;
        if (len1 < len2) {
            for(int i=0; i<len2-len1; ++i)
                pb = pb->next;
        } else if (len1 > len2) {
            for(int i=0; i<len1-len2; ++i)
                pa = pa->next;
        }
        while (pa != nullptr && pb != nullptr) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
private:
    int listLen(ListNode* head) {
        if (head == nullptr)
            return 0;
        int res = 1;
        while (head->next) {
            head = head->next;
            ++res;
        }
        return res;
    }
};

