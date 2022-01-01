class Solution {
public:
    struct Island {
        int area;
        int id;
    };
    
    
    
    void ExploreIsland(const vector<vector<int>>& grid, Island* island, std::vector<std::vector<Island*>>* island_pointers, int y, int x) {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid.size()) {
            return;
        }
        if ((*island_pointers)[y][x] != nullptr) {
            return;
        }
        if (grid[y][x] == 0) {
            return;
        } 
        
        (*island_pointers)[y][x] = island;
        
        island->area++;
        
        
        ExploreIsland(grid, island, island_pointers, y - 1, x);
        ExploreIsland(grid, island, island_pointers, y + 1, x);
        ExploreIsland(grid, island, island_pointers, y, x - 1);
        ExploreIsland(grid, island, island_pointers, y, x + 1);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        std::vector<std::vector<Island*>> island_pointers(grid.size(), std::vector<Island*>(grid.size(), nullptr));
        std::vector<Island> islands;
        islands.reserve(grid.size() * grid.size());
        
        int island_id = 0;
        int max = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid.size(); x++) {
                if (grid[y][x] == 0) {
                    continue;
                }
                // visited.
                if (island_pointers[y][x] != nullptr) {
                    continue;
                }
                Island island;
                island.id = island_id;
                island.area = 0;
                islands.push_back(island);
                ExploreIsland(grid, &islands.back(), &island_pointers, y, x);
                max = std::max(max, islands.back().area);
                cout << "id " << island.id << " area " << islands.back().area;
                island_id++;
            }
        }
        
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid.size(); x++) {
                if (grid[y][x] != 0) {
                    continue;
                }
                // Tries to connect.
                int area = 1;
                std::unordered_set<int> island_ids;
                if (y - 1 >= 0 && grid[y - 1][x] == 1) {
                    Island* island = island_pointers[y - 1][x];
                    if (island_ids.count(island->id) == 0) {
                        area += island->area;
                        island_ids.insert(island->id);
                    }
                }
                if (y + 1 < grid.size() && grid[y + 1][x] == 1) {
                    Island* island = island_pointers[y + 1][x];
                    if (island_ids.count(island->id) == 0) {
                        area += island->area;
                        island_ids.insert(island->id);
                    }
                }
                if (x - 1 >= 0 && grid[y][x - 1] == 1) {
                    Island* island = island_pointers[y][x - 1];
                    if (island_ids.count(island->id) == 0) {
                        area += island->area;
                        island_ids.insert(island->id);
                    }
                }
                if (x + 1 < grid.size() && grid[y][x + 1] == 1) {
                    Island* island = island_pointers[y][x + 1];
                    if (island_ids.count(island->id) == 0) {
                        area += island->area;
                        island_ids.insert(island->id);
                    }
                }
                max = std::max(max, area);
            }
        }
        return max;
    }
};