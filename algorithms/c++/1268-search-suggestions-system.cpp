// https://leetcode.com/problems/search-suggestions-system/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct Trie {
        bool isLeaf = false;
        unordered_map<char, Trie*> children;
    };

    void insert(Trie *root, string s) {
        Trie* pointer = root;
        for (auto &c:s) {
            if (!pointer->children[c])
                pointer->children[c] = new Trie;
            pointer = pointer->children[c];
        }
        pointer->isLeaf = true;
    }
    
    void dfsTrie(Trie* node, string& word, vector<string>& result) {
        if (result.size() == 3)
            return;
        if (node->isLeaf)
            result.push_back(word);
        
        for (int c = 'a'; c <= 'z'; c++) {
            if (node->children[c]) {
                word += c;
                dfsTrie(node->children[c], word, result);
                word.pop_back();
            }
        }
    }
    
    vector<string> wordsWithPrefix(Trie* root, string prefix) {
        vector<string> result;
        Trie* curr = root;
        for (auto &c: prefix) {
            if (!curr->children[c]) {
                return result;
            }
            curr = curr->children[c];
        }
        dfsTrie(curr, prefix, result);
        return result;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *root = new Trie;
        for (int i = 0; i < products.size(); i++) {
            insert(root, products[i]);
        }
        
        vector<vector<string>> full_result;
        string prefix = "";
        for (int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            full_result.push_back(wordsWithPrefix(root, prefix));
        }
        return full_result;
    }
};

int main() {

    return 0;
}