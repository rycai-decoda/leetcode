class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Previous left sums, [0, i), key is the sum, val is # of the sums.
        std::unordered_map<int, int> left_sums;
        int total_sum = 0;
        
        int subarrays = 0;
        
        left_sums[0] = 1;
        
        for (int n : nums) {
            total_sum += n;
            int remainder = total_sum - k;
                        
            if (left_sums.count(remainder) != 0) {
                subarrays += left_sums[remainder];        
            }
            
            // Also updates left_sums.
            left_sums[total_sum]++;
        }
        return subarrays;
    }
};