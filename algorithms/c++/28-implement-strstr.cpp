// https://leetcode.com/problems/implement-strstr/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // KMP Solution

    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int n = haystack.size();
        int m = needle.size();
        if (n < m) return -1;
        // Preprocessing
        int p = 0;
        cout << n << ' ' << m << '\n';
        vector<int> pi(m, 0);
        for (int i = 1; i < m; i++) {
            while (p > 0 && needle[p] != needle[i]) {
                p = pi[p-1];
            }
            if (needle[p] == needle[i]) {
                p++;
            }
            pi[i] = p;
            
        }
        // Matching
        int q = 0;
        for (int i = 0; i < n; i++) {
            while (q > 0 && needle[q] != haystack[i]) {
                q = pi[q-1];
            }
            if (needle[q] == haystack[i]) {
                q++;
                if (q == m) {
                    return i - m + 1;
                }
            }
        }
        return -1;
    }

    // // Naive solution
    // int strStr(string haystack, string needle) {
    //     if (needle == "") return 0;
    //     int n = needle.size();
    //     int h = haystack.size();
    //     for (int i = 0; i <= h - n; i++) {
    //         if (haystack.substr(i, n) == needle) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int sol = Solution().strStr(s1, s2);
    cout << sol << '\n';
    return 0;
}