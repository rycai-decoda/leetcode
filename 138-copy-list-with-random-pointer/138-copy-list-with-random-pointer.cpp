/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        std::unordered_map<Node*, Node*> map;
        for (Node *i = &dummy, *j = head; j != nullptr; i = i->next, j = j->next) {
            Node* new_node = new Node(j->val);
            i->next = new_node;
            map[j] = new_node;
        }
        
        for (Node *i = dummy.next, *j = head; j != nullptr; i = i->next, j = j->next) {
            i->random = map[j->random];
        }
        
        return dummy.next;
    }
};