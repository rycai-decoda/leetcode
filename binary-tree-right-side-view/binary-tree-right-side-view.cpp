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
    vector<int> rightSideView(TreeNode* root) {
        // BFS
        if (root == nullptr) {
            return {};
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int prev;
        std::vector<int> right;
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            // End of a level.
            if (n == nullptr) {
                cout << "nullptr, ";
                right.push_back(prev);
                if (q.empty()) {
                    break;
                }
                q.push(nullptr);
                continue;
            }
            
            prev = n->val;
            cout << prev;
            if (n->left != nullptr) {
                q.push(n->left);
            }
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        return right;
    }
};