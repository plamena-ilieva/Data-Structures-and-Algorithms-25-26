class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;  // We start by adding 1

        // Traverse the digits from last to first
        for (int i = n - 1; i >= 0 && carry; --i) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;      // Update digit
            carry = sum / 10;          // Determine new carry (0 or 1)
        }

        // If there's still a carry, insert 1 at the beginning
        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
