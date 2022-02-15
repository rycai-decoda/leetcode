class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return Eval(s, &i);
    }
    
    int Eval(const string& s, int* i) {
        vector<int> nums;
        char op = '+';
        for (; *i < s.length() && op != ')'; (*i)++) {
            char c = s[*i];
            if (c == ' ') continue;

            long num;

            if (c == '(') {
              (*i)++;
              num = Eval(s, i);
            } else {
              num = Parse(s, i);
            }
            switch(op) {
                case '+' : nums.push_back(num); break;
                case '-' : nums.push_back(-num); break;
                case '*' : nums.back() *= num; break;
                case '/' : nums.back() /= num; break;
            }            
            if (*i < s.length())                  // handle over flow of i in cases like "1 + 1"
                op = s[*i];
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
    
    long Parse(const string& s, int* i) {            // change to long to pass case like "0-2147483648"
        long n = 0;
        while(*i < s.length() && isdigit(s[*i])) {
            n = s[*i] - '0' + 10 * n;
            (*i)++;
        }
            
        return n;
    }
};