class Solution {
public:
    struct NumFreq {
        int num;
        int freq;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, NumFreq*> num_freq_map;
        std::vector<NumFreq> num_freq;
        num_freq.reserve(nums.size());
        for (int n : nums) {
            if (num_freq_map.count(n) == 0) {
                NumFreq new_num;
                new_num.num = n;
                new_num.freq = 0;
                
                num_freq.push_back(std::move(new_num));
                num_freq_map[n] = &num_freq.back();
            }
            
            num_freq_map[n]->freq++;
        }
        
        TopK(num_freq, k, 0, num_freq.size());
        
        std::vector<int> output ;
        
        for (int i = 0; i < k; i++) {
            output.push_back(num_freq[i].num);
        }
        return output;
        
    }
    
    void TopK(std::vector<NumFreq>& num_freq, int k, int begin, int end) {
        if (begin >= end ) {
            return;
        }
        
        int pivot = begin;
        int right = end - 1;
        while (pivot < right) {
            if (num_freq[pivot].freq < num_freq[pivot + 1].freq) {
                std::swap(num_freq[pivot], num_freq[pivot + 1]);
                pivot++;
            } else {
                std::swap(num_freq[pivot + 1], num_freq[right]);
                right--;
            }
        }
        
        if (pivot + 1 == k) {
            return;
        }
        if (pivot + 1 > k) {
            return TopK(num_freq, k, begin, pivot);
        }
        return TopK(num_freq, k, pivot + 1, end);
    }
};