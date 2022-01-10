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
    Node* cloneGraph( Node* const node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> cloned;
        std::queue<Node*> q;
        q.push(node);
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            
            for (Node* adjacent : n->neighbors) {
                
                if (cloned.count(adjacent) != 0) {
                    cloned[n]->neighbors.push_back(cloned[adjacent]);
                    continue;
                }
                
                Node* copy = new Node(adjacent->val);
                cloned[n]->neighbors.push_back(copy);
                cloned[adjacent] = copy;
                q.push(adjacent);
            }
        }
        
        return cloned[node];
    }
};