// https://leetcode.com/problems/maximum-frequency-stack/
#include <bits/stdc++.h>

using namespace std;

class FreqStack {
public:
    int maxVal;
    unordered_map<int,int> counts; // val -> frequency
    unordered_map<int, stack<int>> frequencies; // frequency -> stack<vals>
    
    FreqStack() {
        this->maxVal = 0;
    }
    
    void push(int val) {
        int freq = this->counts[val] + 1;
        this->maxVal = max(freq, this->maxVal);
        this->counts[val] = freq;
        this->frequencies[freq].push(val);
    }
    
    int pop() {
        if (this->maxVal == 0)
            return 0;
        int item = this->frequencies[this->maxVal].top();
        this->counts[item]--;
        this->frequencies[this->maxVal].pop();
        if (this->frequencies[this->maxVal].empty())
            this->maxVal--;
        return item;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {

    return 0;
}