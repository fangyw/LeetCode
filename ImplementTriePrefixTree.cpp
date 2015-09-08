// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : Yuwei Fang
// Date   : 2015-09-08

/********************************************************************************** 
 * 
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/


class TrieNode {
public:
    TrieNode() {
        is_word = false;
    }
public:
    unordered_map<char, TrieNode*> sons;
    bool is_word;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto *p = root;
        for(const auto &ch : word) {
            if (p->sons.find(ch) == p->sons.end()) {
                p->sons[ch] = new TrieNode();
            }
            p = p->sons[ch];
        }
        p->is_word = true;
    }

    bool search(string word) {
        auto *p = root;
        if (find_node(word, p))
            return p->is_word;
        else
            return false;
    }

    bool startsWith(string word) {
        auto *p = root;
        return find_node(word, p);
    }

private:
    bool find_node(const string &word, TrieNode* &p) {
        for(const auto &ch : word) {
            if (p->sons.find(ch) == p->sons.end())
                return false;
            p = p->sons[ch];
        }
        return true;
    }
    TrieNode* root;
};
