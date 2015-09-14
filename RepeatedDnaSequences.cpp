// Source : https://leetcode.com/problems/repeated-dna-sequences/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for 
 * example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify 
 * repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that occur 
 * more than once in a DNA molecule.
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;

        unordered_map<int,int> hash;
        for(int i=0; i<=s.length()-10; ++i) {
            string seq = s.substr(i,10);
            int key = encode(seq);
            hash[key]++;
            if (hash[key] == 2)
                res.push_back(std::move(seq));
        }
        return res;
    }
private:
    int encode(const string& str) {
        int res = 0;
        for(const auto &ch : str) {
            res = res * 4 + ACGT(ch);
        }
        return res;
    }
    int ACGT(const char ch) {
        switch(ch) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                return -1;
        }
    }
};

