// https://leetcode.com/problems/clone-graph/
#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* copy(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr) return nullptr;
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visited.find(node->neighbors[i]) == visited.end())
                copy(node->neighbors[i], visited);
            newNode->neighbors.push_back(visited[node->neighbors[i]]);
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return copy(node, mp);
    }
};

int main() {

    return 0;
}