/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        std::unordered_set<Node*> parents;
        for (Node* n = p; n != nullptr; n = n->parent) {
            parents.insert(n);
        }
        
        for (Node* n = q; n != nullptr; n = n->parent) {
            if (parents.count(n) != 0) {
                return n;
            }
            
        }
        return nullptr;
    }
};