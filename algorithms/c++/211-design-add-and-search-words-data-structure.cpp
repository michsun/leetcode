// https://leetcode.com/problems/design-add-and-search-words-data-structure/
#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
    struct Trie {
        bool isLeaf;
        unordered_map<char, Trie*> children;
    };
public:
    Trie* root;
    
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* prev = root;
        for(auto c: word) {
            if (prev->children.find(c) == prev->children.end())
                prev->children[c] = new Trie();
            prev = prev->children[c];
        }
        prev->isLeaf = true;
    }
    
    bool dfs(Trie* node, string& word, int i) {
        if (i == word.size()) 
            return node->isLeaf;
        
        if (word[i] == '.') {
            for (const auto & it: node->children) {
                if (dfs(it.second, word, i+1))
                    return true;
            }
            return false;
        } else {
            if (node->children.find(word[i]) == node->children.end())
                return false;
            return dfs(node->children[word[i]], word, i+1);
        }
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    cout << '$' - 'a' << '\n';
    return 0;
}