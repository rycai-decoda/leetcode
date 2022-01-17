class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        // Sort by x.
        std::sort(points.begin(), points.end(), [](const auto& p1, const auto& p2) {
            if (p1[0] == p2[0]) {
                return p1[1] < p2[1];
            }
            return p1[0] < p2[0]; 
        });
        
        // map from "y1,y2" to x.
        std::unordered_map<long long, int> x_map;
        int area = INT_MAX;
        for (int i = 0; i < points.size();) {
            int x = points[i][0];
            
            int end = i + 1;
            while (end < points.size() && points[end][0] == x) {
                end++;
            }
            
            for (;i < end; i++) {
            for (int j = i + 1; j < end; j++) {
                int y1 = points[i][1];
                int y2 = points[j][1];
                // std::cout << "i " << i << " j " << j << std::endl;
                // std::cout << "x " << x << " y1 " << y1 << " y2 " << y2 << std::endl;
                
                long long key = (((long long)y1) << 32 ) + y2;
                // std::string key = std::to_string(y1) + "," + std::to_string(y2);
                if (x_map.count(key) == 0) {
                    x_map[key] = x;
                    continue;
                }
                
                
                area = std::min(area, (x - x_map[key]) * (y2 - y1));
                x_map[key] = x;
            }
            }
            
            
            i = end;
        }
        return area == INT_MAX ? 0 : area;
    }
};