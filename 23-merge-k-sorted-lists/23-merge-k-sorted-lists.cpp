/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static bool Comp(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        std::vector<ListNode*> heap_;
        
        for (ListNode* n : lists) {
            if (n == nullptr) {
                continue;
            }
            
            heap_.push_back(n);
            std::push_heap(heap_.begin(), heap_.end(), Comp);
        }
        
        ListNode dummy;
        ListNode* head = &dummy;
        while (!heap_.empty()) {
            ListNode* n = heap_.front();
            std::pop_heap(heap_.begin(), heap_.end(), Comp);
            heap_.pop_back();
            
            head->next = n;
            head = head->next;
            
            if (n->next != nullptr) {
                heap_.push_back(n->next);
                std::push_heap(heap_.begin(), heap_.end(), Comp);
            }
        }
        return dummy.next;
    }
};