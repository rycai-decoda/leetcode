class Solution {
public:
    int calculate(string s) {
        std::vector<int> nums;
        std::vector<char> ops;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (c == ' ') {
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
                    i = n - 1;
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
                
                i = n - 1;
                continue;
            }
            
            ops.push_back(c);
            
        }
        
        
        int res = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            cout << ops[i];
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