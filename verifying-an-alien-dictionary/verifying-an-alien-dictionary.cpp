class Solution {
public:
    bool isAlienSorted(vector<string>& words, const string& order) {
        std::unordered_map<char, int> order_map;
        for (int i = 0; i < order.size(); i++) {
            order_map[order[i]] = i;
        }
        
        return std::is_sorted(words.begin(), words.end(), [&order_map](const std::string& left, const string& right) -> bool {
            
           for (int i = 0; i < left.size() || i < right.size(); i++) {
               int l = -1;
               int r = -1;
               if (i < left.size()) {
                   l = order_map[left[i]];
               }
               if (i < right.size()) {
                   r = order_map[right[i]];
               }
               if (l >  r) {
                   return false;
               }
               
               if (l <  r) {
                   return true;
               }
           }
           
           // Equals.
           return false;
        });
    }
};