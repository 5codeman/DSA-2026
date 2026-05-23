class Solution {
  public:
    int countDigits(int n) {
        // Code here
        if(n == 0) return 0;
        int totalDigit = countDigits(n / 10);
        return 1 + totalDigit;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna