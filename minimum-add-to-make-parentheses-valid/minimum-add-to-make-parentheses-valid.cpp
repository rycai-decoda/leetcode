class Solution {
public:
    int minAddToMakeValid(string s) {
        int left_parentheses = 0;
        int add = 0;
        for (char c : s) {
            if (std::isalpha(c)) {
                continue;
            }
            
            if (c == '(') {
                left_parentheses++;
                continue;
            }
            
            // c == ')'
            if (left_parentheses == 0) {
                add++;
            } else {
                left_parentheses--;
            }
        }
        
        add += left_parentheses;
        return add;
    }
};