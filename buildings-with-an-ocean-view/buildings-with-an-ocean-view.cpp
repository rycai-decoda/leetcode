#include <algorithm>

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int heighest_from_right = 0;
        std::vector<int> views;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > heighest_from_right) {
                views.push_back(i);
                heighest_from_right = std::max(heighest_from_right, heights[i]);
            }
        }
        
        std::reverse(views.begin(), views.end());
        
        return views;
    }
};