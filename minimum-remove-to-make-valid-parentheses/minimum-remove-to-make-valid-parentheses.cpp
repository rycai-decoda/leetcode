class Solution {
public:
    string minRemoveToMakeValid(const string& s) {
        std::vector<int> left_parentheses;
        std::unordered_set<int> remove;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (std::isalpha(c)) {
                continue;
            }
            if (c == '(') {
                left_parentheses.push_back(i);
                continue;
            }
            // is )
            if (left_parentheses.empty()) {
                remove.insert(i);
            } else {
                left_parentheses.pop_back();
            }
        }
        while (!left_parentheses.empty()) {
            remove.insert(left_parentheses.back());
            left_parentheses.pop_back();
        }
        
        std::string removed;
        for (int i = 0; i < s.size(); i++) {
            if (remove.count(i) == 0) {
                removed.push_back(s[i]);
            }
        }
        return removed;
    }
};