class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.size() == 0) {
            return {};
        }
        
        int y = 0, x = 0;
        int dir_y = -1, dir_x = +1;
        
        std::vector<int> output;
        while (inrange(mat, y, x)) {
            
            cout << "y " << y << " x " << x << endl;
            output.push_back(mat[y][x]);
            
            y += dir_y;
            x += dir_x;
            
            if (inrange(mat, y, x)) {
                continue;
            }
            
            bool top_right = dir_y == -1;
            
            dir_y = 0 - dir_y;
            dir_x = 0 - dir_x;
            
            if (top_right) {
                y += 1;
                if (inrange(mat, y, x)) {
                    continue;
                }
                y += 1;
                x -= 1;
                if (inrange(mat, y, x)) {
                    continue;
                }
                continue;
            }
            
            // left bottom
            
            x += 1;
            if (inrange(mat, y, x)) {
                continue;
            }
            
            x += 1;
            y -= 1;
            if (inrange(mat, y, x)) {
                continue;
            }
            continue;
        }
        
        return output;
        
    }
    
    bool inrange(vector<vector<int>>& mat, int y, int x) {
        return y >= 0 && y < mat.size() && x >= 0 && x < mat[0].size();
    }
};