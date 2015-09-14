// Source : https://leetcode.com/problems/min-stack/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in 
 * constant time.
 * 
 * push(x) -- Push element x onto stack.
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * top() -- Get the top element.
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class MinStack {
public:
    void push(int x) {
        if (min_.empty() || x <= min_.top())
            min_.push(x);
        elem_.push(x);
    }

    void pop() {
        if (!elem_.empty()) {
            if (min_.top() == elem_.top())
                min_.pop();
            elem_.pop();
        }
    }

    int top() {
        if (!elem_.empty())
            return elem_.top();
        return 0;
    }
    
    int getMin() {
        if (!min_.empty())
            return min_.top();
        return 0;
    }
private:
    stack<int> elem_;
    stack<int> min_;
};

