// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Yuwei Fang
// Date   : 2015-09-08

/********************************************************************************** 
 * 
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while 
 * preserving the order of characters. No two characters may map to the same character 
 * but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 *               
 **********************************************************************************/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> hash_s;
        unordered_map<char, int> hash_t;

        for(int i=0; i<s.length(); ++i) {
            if (hash_s.find(s[i]) == hash_s.end() && hash_t.find(t[i]) == hash_t.end()) {
                hash_s.emplace(s[i], i);
                hash_t.emplace(t[i], i);
            } else if (hash_s.find(s[i]) != hash_s.end() && hash_t.find(t[i]) != hash_t.end()) {
                if (hash_s[s[i]] != hash_t[t[i]])
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

