/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        current_ = root;
        // if (root != nullptr) {
        //     stack_.push(root);
        // }
    }
    
    int next() {
        if (!hasNext()) {
            throw std::runtime_error("No more next !");
        }
         
        
        
        while (current_ != nullptr) {
            stack_.push(current_);
            current_ = current_->left;
        }
        
        TreeNode* node = stack_.top();
        stack_.pop();
        int val = node->val;
        current_ = node->right;
        
        // if (current->right) {
        //     stack_.push(current->right);
        // }
        // if (current->left) {
        //     stack_.push(current->left);
        // }
        
        return val;
    }
    
    bool hasNext() {
        return current_ != nullptr || !stack_.empty();
    }
    
    std::stack<TreeNode*> stack_;
    TreeNode* current_ = nullptr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */