class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::unordered_set<char> chars;
        for (char c : s) {
            if (chars.count(c)) {
                chars.erase(c);
            } else {
                chars.insert(c);
            }
        }
        
        return chars.size() < 2;
    }
};