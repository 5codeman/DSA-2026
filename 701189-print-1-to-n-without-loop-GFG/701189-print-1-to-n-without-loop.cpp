class Solution {
  public:
    void printNos(int n) {
        // Code here
        if(n < 1) return;
        printNos(n - 1);
        cout << n << " ";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna