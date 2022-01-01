class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        std::string sum;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            int digit = 0;
            if (i1 >= 0) {
                digit += num1[i1] - '0';
            }
            if (i2 >= 0) {
                digit += num2[i2] - '0';
            }
            digit += carry;
            sum.push_back('0' + digit % 10);
            carry = digit / 10;
            i1--;
            i2--;
        }
        std::reverse(sum.begin(), sum.end());
        return sum;
    }
};