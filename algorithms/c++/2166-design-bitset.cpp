// https://leetcode.com/problems/design-bitset/
#include <bits/stdc++.h>

using namespace std;

class Bitset {
public:
    string s, r;
    int size;
    int counter;
    
    Bitset(int size) {
        this->s = string(size, '0');
        this->r = string(size, '1');
        this->size = size;
        this->counter = 0;
    }
    
    void fix(int idx) {
        if (s[idx] == '0') this->counter++;
        s[idx] = '1';
        r[idx] = '0';
    }
    
    void unfix(int idx) {
        if (s[idx] == '1') this->counter--;
        s[idx] = '0';
        r[idx] = '1';
    }
    
    void flip() {
        swap(s, r);
        this->counter = this->size - this->counter;
    }
    
    bool all() {
        return (this->counter == this->size);
    }
    
    bool one() {
        return this->counter > 0;
    }
    
    int count() {
        return this->counter;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main() {

    return 0;
}