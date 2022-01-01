class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        
        // sums of subsusets [0, i - 2];
        std::unordered_set<int> prev_sums;
        int prev_sum = 0;
        prev_sums.insert(0);
        
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            
            for (int m = (sum - prev_sum) / k; m * k <= sum; m++) {
                int remainder = sum - m * k;
                if (prev_sums.count(remainder) != 0) {
                    return true;
                }
            }
            
            prev_sum += nums[i - 1];
            prev_sums.insert(prev_sum);
        }
        
        return false;
    }
};