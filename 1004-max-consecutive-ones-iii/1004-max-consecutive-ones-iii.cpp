class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest = 0;
        
        int start = 0;
        int end = 0;
        int zeros = 0;
        
        while (end < nums.size()) {
            if (nums[end] == 0) {
                zeros++;
            }
            
            // Moves start to recover <= k zeros
            while (zeros > k) {
                if (nums[start] == 0) {
                    zeros--;
                    
                } 
                start++;
            }
            longest = std::max(longest, end - start + 1);
            end++;
        }
        
        return longest;
    }
};