class Solution {
public:
    bool ValidPalindrome(const string& s, int l, int r, int* deleted) {
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            
            if (*deleted >= 1) {
                return false;
            }
            
            (*deleted)++;
            return ValidPalindrome(s, l + 1, r, deleted) || ValidPalindrome(s, l, r - 1, deleted);
        }
        return true;
    }
    bool validPalindrome(const string& s) {
        
        int deleted = 0;
        return ValidPalindrome(s, 0, s.size() - 1, &deleted);
    }
};