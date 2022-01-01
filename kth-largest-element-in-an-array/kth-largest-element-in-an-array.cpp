class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k > nums.size()) {
            throw std::runtime_error("K > nums.size()");
        }
        
        return findKthLargest(nums, k, 0, nums.size());
    }
    
private:
    int findKthLargest(vector<int>& nums, int k, int begin, int end) {
        if (begin >= end - 1) {
            return nums[begin];
        }
        
        int pivot = nums[begin];
        int left = begin;
        int right = end - 1;
        while (left < right) {
            if (nums[left + 1] > pivot) {
                std::swap(nums[left + 1], nums[left]);
                left++;
            } else {
                std::swap(nums[left + 1], nums[right]);
                right--;
            }
        }
        nums[left] = pivot;
        
        
        // left # of nums < pivot.
        if (left == k - 1) {
            return nums[left];
        }
        
        if (left < k - 1) {
            return findKthLargest(nums, k, left + 1, end);
        }
        return findKthLargest(nums, k, begin, left);
    }
};