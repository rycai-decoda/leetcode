class Solution {
public:
    Solution(vector<int>& w) : landmarks_(w.size()) {
        
        // +----)------+--------)
        //    0     1      2
        for (int i = 0; i < w.size(); i++) {
            sum_ += w[i];
            landmarks_[i] = sum_;
        }
        
    }
    
    // Binary search the landmarks.
    // Generates n = rand(0 - sum_)
    // Finds the first i that landmarks_[i] >= n
    int pickIndex() {
        int rand = std::rand() % (sum_);
        auto it = std::upper_bound(landmarks_.begin(), landmarks_.end(), rand);    
        return it - landmarks_.begin();
    }
    
    std::vector<int> landmarks_;
    int sum_ = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */