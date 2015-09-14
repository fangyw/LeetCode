// Source : https://leetcode.com/problems/compare-version-numbers/
// Author : Yuwei Fang
// Date   : 2015-09-14

/********************************************************************************** 
 * 
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 
 * 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and 
 * the . character.
 * The . character does not represent a decimal point and is used to separate number 
 * sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the 
 * fifth second-level revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = split(version1, '.');
        vector<int> vec2 = split(version2, '.');

        trimRightZero(vec1);
        trimRightZero(vec2);

        for(int i=0; i<vec1.size() && i<vec2.size(); ++i) {
            if (vec1[i] > vec2[i]) {
                return 1;
            } else if (vec1[i] < vec2[i]) {
                return -1;
            }
        }
        if (vec1.size() > vec2.size())
            return 1;
        else if (vec1.size() < vec2.size())
            return -1;
        return 0;
    }
private:
    vector<int> split(const string &word, char delim) {
        vector<int> res;
        int state = 0;
        int start = 0;
        for(int i=0; i<word.size(); ++i) {
            if (state == 0) { // OUT
                if (word[i] != '.') {
                    state = 1;
                    start = i;
                }
            } else { // IN
                if (word[i] == '.') {
                    res.push_back(stoi(word.substr(start, i-start)));
                    start = i+1;
                    state = 0;
                }
            }
        }
        if (state == 1) { // IN
            res.push_back(stoi(word.substr(start)));
        }
        return res;
    }

    void trimRightZero(vector<int> &vec) {
        while (vec.back() == 0) {
            vec.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string v1("1.1.1.");
    string v2("1.1.1.0");
    cout << sol.compareVersion(v1, v2) << endl;
}
