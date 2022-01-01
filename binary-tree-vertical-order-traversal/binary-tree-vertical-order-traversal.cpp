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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        std::unordered_map<int, std::vector<int>> placements;
        FindPosition(root, &placements);
        
        int min_col = 0;
        int max_col = 0;
        for (const auto& it : placements) {
            min_col = std::min(min_col, it.first);
            max_col = std::max(max_col, it.first);
        }
        
        std::vector<std::vector<int>> output(max_col - min_col + 1);
        for (const auto& it : placements) {
            output[it.first - min_col] = it.second;
        }
        return output;
    }
    
private:
    struct Pos {
        
        int row;
        int col;
    };

    
    void FindPosition(TreeNode* root, std::unordered_map<int, std::vector<int>>* placements) {
        if (root == nullptr) {
            return;
        }
        
        std::queue<TreeNode*> q;
        std::unordered_map<TreeNode*, int> col_map;
        q.push(root);

        col_map[root] = 0;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int col = col_map[node];
            
            if (node->left != nullptr) {
                col_map[node->left] = col - 1;
                q.push(node->left);
            }
            if (node->right != nullptr) {
                col_map[node->right] = col + 1;
                q.push(node->right);
            }
            
            (*placements)[col].push_back(node->val);
        }

    }
};