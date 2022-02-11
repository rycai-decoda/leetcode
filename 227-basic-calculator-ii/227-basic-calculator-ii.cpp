class Solution {
public:
    int calculate(string s) {
        std::vector<int> nums;
        std::vector<char> ops;
        
        for (int i = 0; i < s.size();) {
            char c = s[i];
            
            if (c == ' ') {
                i++;
                continue;
            }
            
            
            
            if (std::isdigit(c)) {
                int n = i;
                while (n < s.size() && std::isdigit(s[n])) {
                    n++;
                }
                int num = std::stoi(s.substr(i, n - i));
                if (ops.empty()) {
                    nums.push_back(num);
                    i = n;
                    continue;
                }
                if (ops.back() == '*') {
                    nums.back() *= num;
                    ops.pop_back();
                } else if (ops.back() == '/') {
                    nums.back() /= num;
                    ops.pop_back();
                } else {
                    nums.push_back(num);
                }
                
                i = n;
                continue;
            }
            
            ops.push_back(c);
            i++;
        }
        
        
        int res = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') {
                res += nums[i + 1];
            }
            if (ops[i] == '-') {
                res -= nums[i + 1];
            }
        }
        return res;
    }
};