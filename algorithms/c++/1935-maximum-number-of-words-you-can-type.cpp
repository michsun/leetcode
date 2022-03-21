// https://leetcode.com/problems/maximum-number-of-words-you-can-type/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> letters;
        for (int i = 0; i < brokenLetters.size(); i++)
            letters.insert(brokenLetters[i]);
        int count = 0;
        string word = "";
        bool found = false;
        for (auto &c: text) {
            if (c != ' ') {
                word.push_back(c);
                if (letters.find(c) != letters.end())
                    found = true;
            } else {
                if (!found) count++;
                word = "";
                found = false;
            }
        }
        if (!found) count++;
        return count;
    }
};

int main() {

    return 0;
}