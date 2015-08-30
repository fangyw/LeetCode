// Source : https://leetcode.com/problems/implement-stack-using-queues/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Implement the following operations of a stack using queues.
 * 
 * push(x) -- Push element x onto stack.
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * top() -- Get the top element.
 * 
 * empty() -- Return whether the stack is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a queue -- which means only push to back, 
 * peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a 
 * queue by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations 
 * will be called on an empty stack).
 * 
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and all test 
 * cases.
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <queue>
using namespace std;

class Stack {
public:
    void push(int x) {
        que_.emplace(x);
    }

    void pop() {
        adjust();
        if (!que_.empty())
            que_.pop();
    }

    int top() {

        adjust();

        int res = INT_MIN;
        if (!que_.empty()) {
            res = que_.front();
            que_.push(res);
            que_.pop();
        }
        return res;
    }

    bool empty() {
        return que_.empty();
    }
private:
    void adjust() {
        for(int i=1; i<que_.size(); ++i) {
            que_.push(que_.front());
            que_.pop();
        }
    }
    queue<int> que_;
};
