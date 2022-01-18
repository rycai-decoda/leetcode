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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> output;
        while (!q.empty()) {
            int row_size = q.size();
            int largest = INT_MIN;
            for (int i = 0; i < row_size; i++) {
                TreeNode* n = q.front();
                q.pop();
                
                largest = std::max(largest, n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
                
            }
            output.push_back(largest);
        }
        return output;
    }
};