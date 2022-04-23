// https://leetcode.com/problems/encode-and-decode-tinyurl/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, string> encoded;
    unordered_map<string, string> decoded;
    string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = characters.size();
    string tinyUrl = "http://tinyurl.com/";
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encoded.find(longUrl) == encoded.end()) {
            string shortUrl;
            do {
                shortUrl = tinyUrl;
                for (int i = 0; i < 6; i++) 
                    shortUrl += characters[rand() % n];
            } while (decoded.find(shortUrl) != decoded.end());
            encoded[longUrl] = shortUrl;
            decoded[shortUrl] = longUrl;
        }
        return encoded[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoded[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {

    return 0;
}