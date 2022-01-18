#include <algorithm>
#include <numeric>


class Solution {
public:
    
    bool canShip(const vector<int>& weights, int capacity, int days) {
        int load = 0;
        for (int w : weights) {
            if (load + w > capacity) {
                days--;
                load = w;
            } else {
                load += w;
            }
            
            
        }
        if (load > 0) {
            days--;
        }
        return days >= 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = *std::max_element(weights.begin(), weights.end());
        int sum = std::accumulate(weights.begin(), weights.end(), 0);
        
        std::vector<int> range;
        for (int n = max_weight; n <= sum; n++) {
            range.push_back(n);
        }
        
        auto it = std::lower_bound(range.begin(), range.end(), days, 
                                   [this, &weights](int capacity, int days){
            // returns true if *it < value.
            // returns true if cannot ship.                 
            return !canShip(weights, capacity, days);
        });
        
        return *it;
    }
};