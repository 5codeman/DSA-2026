class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
        if(n == 0) return 0;
        int total_sum = sumOfDigits(n / 10);
        return total_sum += (n % 10);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna