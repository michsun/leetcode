// https://leetcode.com/problems/repeated-dna-sequences/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Solution using Rabin-Karp algorithm
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if (n < 10) return ans;
        
        // Encodes input alphabet
        unordered_map<char, int> mp = {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3}
        };
        
        int hash = 0; 
        int d = 4;
        int h = 1;
        // Does not need prime as total possible values = 4 ^ 10 = 1048576 < INT_MAX
        
        for (int i = 0; i < 10 - 1; i++) 
            h *= d;
        
        // Initial hash value for the first 10 characters
        for (int i = 0; i < 10; i++) 
            hash = (d * hash + mp[s[i]]);
        
        unordered_map<int, int> hashes;
        hashes[hash] = 0;
        
        for (int i = 1; i <= n - 10; i++) {
            // Calculate new hash value using sliding wndow
            hash = d * (hash - mp[s[i-1]]*h) + mp[s[i+10-1]] ;
            if (hashes.find(hash) != hashes.end()) {
                if (hashes[hash] == 0) {
                    hashes[hash] = 1;
                    ans.push_back(s.substr(i, 10));
                }
            } else {
                hashes[hash] = 0;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}