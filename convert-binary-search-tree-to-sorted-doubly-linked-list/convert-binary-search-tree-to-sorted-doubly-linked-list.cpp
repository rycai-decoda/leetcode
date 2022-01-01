/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node head;
        Node tail;
        Flattern(root, &head, &tail);
        tail.left->right = head.right;
        head.right->left = tail.left;
        return head.right;
    }
private:
    void Flattern(Node* root, Node* head, Node* tail) {
        if (root == nullptr) {
            return;
        }
        
        head->right = root;
        tail->left = root;
        Node* left_child = root->left;
        Node* right_child = root->right;
        
        root->left = head;
        root->right = tail;
        Flattern(left_child, head, root);
        Flattern(right_child, root, tail);
    }
    
};