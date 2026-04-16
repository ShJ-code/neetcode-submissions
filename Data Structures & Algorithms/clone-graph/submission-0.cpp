/*
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
*/

class Solution {
public:
    unordered_map<Node*, Node*> mem;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* res = new Node(node->val, vector<Node*>(node->neighbors.size()));
        mem.insert({node, res});
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (mem.contains(node->neighbors[i])) {
                res -> neighbors[i] = mem.find(node->neighbors[i])->second;
            } else {
                res -> neighbors[i] = cloneGraph(node->neighbors[i]);
            }
        }
        return res;
    }
};
