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
    void dfs(TreeNode *node, int num, int *sum) {
        if (node == nullptr) {
            
            return;
        }
        
        num = 10 * num + node->val;
        
        if (node->left == nullptr && node->right == nullptr) {
            *sum += num;
            return;
        }
        
        
        
        dfs(node->left, num, sum);
        dfs(node->right, num, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, &sum);
        
        return sum;
    }
};