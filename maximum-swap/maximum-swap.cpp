class Solution {
public:
    int maximumSwap(int num) {
        if (num < 10) {
            return num;
        }
        std::vector<int> digits;
        for (int n = num; n > 0; n = n / 10) {
            digits.push_back(n % 10);
        }
        std::reverse(digits.begin(), digits.end());
        
        std::vector<int> max_index(digits.size());
        int current_max = digits.size() - 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > digits[current_max]) {
                max_index[i] = i;
                current_max = i;
            } else {
                max_index[i] = current_max;
            }
        }
        
        for (int n : max_index) {
            cout << n << ",";
        }
        cout << endl;

        int swap_left = -1;
        int swap_right = -1;
        for (int i = 0; i < digits.size() - 1; i++) {
            if (digits[i] < digits[max_index[i + 1]]) {
                swap_left = i;
                swap_right = max_index[i + 1];
                break;
            }
        }
        
        if (swap_left < 0) {
            return num;
        }
        
        std::swap(digits[swap_left], digits[swap_right]);
        
        int output = 0;
        for (int d : digits) {
            output = 10 * output + d;
        }
        return output;
    }
};