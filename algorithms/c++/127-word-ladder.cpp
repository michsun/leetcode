// https://leetcode.com/problems/word-ladder/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordExists(vector<string>& list, string& word) {
        for (auto& s: list)
            if (word == s)
                return true;
        return false;
    }
    
    bool isAdjacent(string& s1, string& s2) {
        int diffChars = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                diffChars++;
        }
        return diffChars == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Find if endWord exists in wordList
        if (!wordExists(wordList, endWord))
            return 0;
        
        // From wordlist, generate a tree from wordList
        int count = 0;
        queue<queue<string>> tree;
        queue<string> layer;
        layer.push(beginWord);
        tree.push(layer);
        while(!tree.empty()) {
            queue<string> currLayer = tree.front();
            tree.pop();
            count++;
            
            queue<string> newLayer;
            stack<int> wordsToRemove;
            
            while(!currLayer.empty()) {
                string currWord = currLayer.front();
                currLayer.pop();
                // Finds adjacent words
                for (int i = 0; i < wordList.size(); i++) {
                    if (isAdjacent(currWord, wordList[i])) {
                        if (wordList[i] == endWord)
                            return ++count;
                        newLayer.push(wordList[i]);
                        wordsToRemove.push(i);
                    }
                }
                while(!wordsToRemove.empty()) {
                    int pos = wordsToRemove.top();
                    wordsToRemove.pop();
                    wordList.erase(wordList.begin()+pos);
                }
            }
            
            if (!newLayer.empty()) {
                tree.push(newLayer);
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}