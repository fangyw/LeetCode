// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * peek() -- Get the front element.
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, 
 * peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a 
 * stack by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations 
 * will be called on an empty queue).
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

#include <stack>

using namespace std;
class Queue {
public:
    void push(int x) {
        stk1.emplace(x);
    }

    void pop(void) {
        peek();
        if (!stk2.empty())
            stk2.pop();
    }

    int peek(void) {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.emplace(stk1.top());
                stk1.pop();
            }
        }
        if (!stk2.empty())
            return stk2.top();
        else
            return INT_MIN;
    }

    bool empty(void) {
        return stk1.empty() && stk2.empty();
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};
