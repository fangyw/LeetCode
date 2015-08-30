// Source : https://leetcode.com/problems/basic-calculator/
// Author : Yuwei Fang
// Date   : 2015-08-30

/********************************************************************************** 
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus + or 
 * minus sign -, non-negative integers and empty spaces  .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * 
 * Note: Do not use the eval built-in library function.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> optr;
        stack<int> opnd;
        
        s += "+0";
        const int n = s.length();

        for(int i=0; i<n; ++i) {
            if (isOperator(s[i])) {
                if (optr.empty() || s[i] == '(' || precedence(s[i]) > precedence(optr.top())) {
                    optr.push(s[i]);
                } else { // need calculate
                    int y = opnd.top();
                    opnd.pop();
                    int x = opnd.top();
                    opnd.pop();
                    opnd.push(calculate(optr.top(), x, y));
                    optr.pop();
                    --i;
                }
            } else if (s[i] == ')') {
                char op = optr.top();
                optr.pop();

                while (op != '(') {
                    int y = opnd.top();
                    opnd.pop();
                    int x = opnd.top();
                    opnd.pop();
                    opnd.push(calculate(op,x,y));

                    op = optr.top();
                    optr.pop();
                }
            } else if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                opnd.push(num);
                --i;
            }

        }

        int y = opnd.top();
        opnd.pop();
        int x = opnd.top();
        opnd.pop();
        return calculate(optr.top(), x,y);

    }
private:
    int precedence(char op) {
        if(op == '(')
            return 1;
        else if (op == '+' || op == '-')
            return 2;
        else if (op == '*' || op == '/')
            return 3;
        return 4;
    }
    int calculate(char op, int x ,int y) {
        if (op == '+')
            x += y;
        else if (op == '-')
            x -= y;
        else if (op == '*')
            x *= y;
        else if (op == '/')
            x /= y;

        return x;
    }

    bool isOperator(char op) {
        return op == '(' || op == '+' || op == '-' || op == '*' || op == '/';
    }
};

int main() {
    Solution sol;
    //vector<string> expr{"3+2*2", " 3/2 ", " 3+5 / 2 "};
    vector<string> expr{"3+2*2"};
    for(const auto &str : expr)
        cout << sol.calculate(str) << endl;
    return 0;
}
