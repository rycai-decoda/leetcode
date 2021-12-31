class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                continue;
            }
            
            index_num_[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int product = 0;
        for (const auto& it : index_num_) {
            int index = it.first;
            int num = it.second;
            
            if (vec.index_num_.count(index) != 0) {
                product += num * vec.index_num_[index];
            }
        }        
        return product;
    }

private:
    
    std::unordered_map<int, int> index_num_;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);