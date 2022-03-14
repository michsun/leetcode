// https://leetcode.com/problems/simplify-path/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void collectBuffer(string& buffer, vector<string>& vec) {
        if (buffer == "." || buffer == "")
            return;
        if (buffer == ".." && vec.size() > 0)
            vec.pop_back();
        if (buffer != "..")
            vec.push_back(buffer);
    }
    
    string simplifyPath(string path) {
        vector<string> canonical;
        string buffer = "";
        for (auto & c : path) {
            if (c == '/') {
                collectBuffer(buffer, canonical);
                buffer = "";
            } else {
                buffer += c;
            }
        }
        collectBuffer(buffer, canonical);
        
        string output;
        for (auto& s : canonical)
            output += "/" + s;
        if (output.size() == 0)
            output = "/";
        return output;
    }
};

int main() {

    return 0;
}