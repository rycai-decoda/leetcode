class Solution {
public:
    int calculate(string s) {
      std::vector<int> context_signs({1});
      int current_sign = 1;
      int eval_result = 0;
      for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ' ') {
          continue;
        }
        
        if (c == '+') {
          current_sign = context_signs.back();
          continue;
        }
        if (c == '-') {
          current_sign = 0 - context_signs.back();
          continue;
        }

        if (c == '(') {
          context_signs.push_back(current_sign);
          continue;
        }

        if (c == ')') {
          context_signs.pop_back();
          continue;
        }

        // If digits.
        int nondigit = i + 1;
        while (nondigit <= s.size()) {
          if (!std::isdigit(s[nondigit])) {
            break;
          }
          nondigit++;
        }

        int num = std::stoi(s.substr(i, nondigit - i));
        eval_result += current_sign * num;
        i = nondigit - 1;
      }

      return eval_result;
    }
};