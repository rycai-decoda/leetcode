/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* n = new Node(insertVal);
        if (head == nullptr) {
            
            n->next = n;
            return n;
        }
        
        if (head == head->next) {
            n->next = head;
            head->next = n;
            return head;
        }
        
        Node *current = head, *next = head->next;
        
        Node *min_node = head->next;
        Node *max_node = head;
        
        do {
            if (current->val >= max_node->val && next->val <= min_node->val) {
                max_node = current;
                min_node = next;
            }
                    
                
            if (insertVal >= current->val && insertVal <= next->val) {
                n->next = next;
                current->next = n;
                return head;
            }
            current = current->next;
            next = next->next;
        } while (current != head);
        
        n->next = min_node;
        max_node->next = n;
        
        return head;
    }
};