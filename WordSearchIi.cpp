// Source : https://leetcode.com/problems/word-search-ii/
// Author : Yuwei Fang
// Date   : 2015-09-06

/********************************************************************************** 
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in the 
 * board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell, where 
 * "adjacent" cells are those horizontally or vertically neighboring. The same letter 
 * cell may not be used more than once in a word.
 * 
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board = 
 * 
 * [
 *   ['o','a','a','n'],
 *   ['e','t','a','e'],
 *   ['i','h','k','r'],
 *   ['i','f','l','v']
 * ]
 * 
 * Return ["eat","oath"].
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 * click to show hint.
 * 
 * You would need to optimize your backtracking to pass the larger test. Could you stop 
 * backtracking earlier?
 * 
 * If the current candidate does not exist in all words' prefix, you could stop 
 * backtracking immediately. What kind of data structure could answer such query 
 * efficiently? Does a hash table work? Why or why not? How about a Trie? If you would 
 * like to learn how to implement a basic trie, please work on this problem: Implement 
 * Trie (Prefix Tree) first.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Trie {
public:
    unordered_map<char, Trie*> sons;
    bool is_word;
    Trie() {
        is_word = false;
    }   
    void add(const string &word) {
        auto *p = this;
        for(const auto &ch : word) {
            if (p->sons.find(ch) == p->sons.end()) {
                p->sons[ch] = new Trie();
            }
            p = p->sons[ch];
        }
        p->is_word = true;
    }
    ~Trie() {
        for(auto &kv: sons) {
           if (kv.second) {
               kv.second->~Trie();
           }
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string>& words) {
        const int m = board.size();
        const int n = board[0].size();
        Trie trie;
        for(const auto &word : words)
            trie.add(word);
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_set<string> res;
        string path;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                dfs(i,j,&trie,path,board,visited,res);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(int i, int j, Trie *node, string path, const vector<vector<char>> &board,
             vector<vector<bool>> &visited, unordered_set<string> &res) {
        if (i<0 || i>= board.size() || j<0 || j>= board[0].size() || !node)
            return;
        if (visited[i][j] || node->sons.find(board[i][j]) == node->sons.end())
            return;
        node = node->sons[board[i][j]];
        path += board[i][j];
        if (node->is_word) {
            res.insert(path);
        }
        visited[i][j] = true;
        vector<pair<int,int>> directions{{-1,0}, {1,0}, {0,1},{0,-1}};
        for(int k=0; k<directions.size(); ++k) {
            int xi = directions[k].first + i;
            int xj = directions[k].second + j;
            dfs(xi,xj,node,path,board,visited,res);
        }
        visited[i][j] = false;
    }
};


int main() {
    vector<string> words{"oath","pea","eat","rain"};
    vector<vector<char>> board{
          {'o','a','a','n'},
          {'e','t','a','e'},
            {'i','h','k','r'},
              {'i','f','l','v'}
                  };
    Solution sol;
    auto res = sol.findWords(board, words);
    for(const auto &val : res)
        cout << val << endl;
    return 0;
}
