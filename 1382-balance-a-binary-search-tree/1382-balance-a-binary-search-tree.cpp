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
class Solution {
public:
    void traverse(TreeNode* root, std::vector<int>* inorder) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left, inorder);
        inorder->push_back(root->val);
        
        traverse(root->right, inorder);
    }
    
    TreeNode* build(const std::vector<int>& inorder, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }
        
        int mid = (begin + end) / 2;
        
        TreeNode* node = new TreeNode(inorder[mid]);
        
        node->left = build(inorder, begin, mid - 1);
        node->right = build(inorder, mid + 1, end);
        
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> inorder;
        traverse(root, &inorder);
        
        TreeNode* new_root = build(inorder, 0, inorder.size() - 1);
        
        return new_root;
    }
};