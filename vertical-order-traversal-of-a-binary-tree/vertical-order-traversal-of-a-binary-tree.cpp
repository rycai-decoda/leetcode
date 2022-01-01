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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::unordered_map<TreeNode*, std::pair<int, int>> positions;
        std::queue<TreeNode*> q;
        q.push(root);
        positions[root] = {0, 0};
        
        std::vector<TreeNode*> nodes;
        
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            nodes.push_back(n);
            std::pair<int, int> pos = positions[n];
            
            if (n->left) {
                positions[n->left] = {pos.first - 1, pos.second + 1};
                q.push(n->left);
            }
            
            if (n->right) {
                positions[n->right] = {pos.first + 1, pos.second + 1};
                q.push(n->right);
            }
        }
        
        std::sort(nodes.begin(), nodes.end(),
                  [&positions](TreeNode* n1, TreeNode* n2) {
            const auto& pos1 = positions[n1];
            const auto& pos2 = positions[n2];
            if (pos1.first < pos2.first) {
                return true;
            }
            if (pos1.first > pos2.first) {
                return false;
            }
            // col1 == col2
            if (pos1.second < pos2.second) {
                return true;
            }
            if (pos1.second > pos2.second) {
                return false;
            }
            return n1->val < n2->val;
        
        });
        int col = INT_MIN;
        std::vector<std::vector<int>> output;
        for (TreeNode* n : nodes) {
            if (col != positions[n].first) {
                col = positions[n].first;
                output.push_back({});
            }
            output.back().push_back(n->val);   
            
        }
        return output;
    }
};