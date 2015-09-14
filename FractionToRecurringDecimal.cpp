// Source : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Given two integers representing the numerator and denominator of a fraction, return 
 * the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * 
 * Credits:Special thanks to @Shangrila for adding this problem and creating all test 
 * cases.
 *               
 **********************************************************************************/
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        if (denominator == 0)
            return to_string(INT_MAX);

        long long abs_num = llabs(numerator);
        long long abs_denom = llabs(denominator);

        string int_part = to_string(abs_num / abs_denom);
        long long remaind = abs_num % abs_denom;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            int_part = "-" + int_part;
        }
        if (remaind == 0)
            return int_part;

        string frac_part;
        int pos = 0;
        unordered_map<long long, int> hash;
        while (remaind) {
            if (hash.find(remaind) != hash.end()) {
                frac_part.insert(frac_part.begin() + hash[remaind], '(');
                frac_part.push_back(')');
                break;
            }
            hash[remaind] = pos;
            frac_part.push_back((remaind*10)/abs_denom + '0');
            remaind = (remaind*10) % abs_denom;
            ++pos;
        }
        return int_part + "." + frac_part;
    }
};


int main() {
    Solution sol;
    int numerator = -10;
    int denominator = 3;
    cout << sol.fractionToDecimal(numerator, denominator);
}
