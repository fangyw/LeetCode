// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author : Yuwei Fang
// Date   : 2015-09-07

/********************************************************************************** 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * search(word) can search a literal word or a regular expression string containing 
 * only letters a-z or .. A . means it can represent any one letter.
 * 
 * For example:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 * click to show hint.
 * 
 * You should be familiar with how a Trie works. If not, please work on this problem: 
 * Implement Trie (Prefix Tree) first.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class WordDictionary {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> sons;
        bool is_word = false;
    };

    WordDictionary() {
        root = new TrieNode;
        root->is_word = false;
    }

    void addWord(string word) {
        auto *p = root;
        for(const auto &ch : word) {
            if (p->sons.find(ch) == p->sons.end()) {
                p->sons[ch] = new TrieNode;
            }
            p = p->sons[ch];
        }
        p->is_word = true;
    }

    bool search(string word) {
        return search(word, root, 0);
    }
private:
    bool search(const string& str, TrieNode* node, int start) {
        if (start == str.length()) {
            return node->is_word;
        }

        if (node->sons.find(str[start]) != node->sons.end()) {
            return search(str, node->sons[str[start]], start+1);
        } else if (str[start] == '.') {
            for(const auto &son : node->sons) {
                if (search(str, son.second, start+1)) {
                    return true;
                }
            }
        }
        return false;
    }
    TrieNode *root;
};

