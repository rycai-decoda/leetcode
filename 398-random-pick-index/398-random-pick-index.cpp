class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            index_[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const std::vector<int>& index = index_[target];
        
        return index[std::rand() % index.size()];
    }
    
private:
    std::unordered_map<int, std::vector<int>> index_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */