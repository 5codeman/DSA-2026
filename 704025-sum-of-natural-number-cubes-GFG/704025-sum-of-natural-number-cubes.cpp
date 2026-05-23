// User function template for C++

class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        
        // Approach1 - Here we can solve this q by run the loop till n and for each i we can multiply like I * i * i;
        // Approach2 - as we know sum of series of cube is equal to the square of the summation of all the series - eg - 1^3 + 2^3 + 3^3 + 4^3 = (1 + 2 + 3 + 4)^2; - we can solve it by summation formulla.
        
        // For now I am doing with itrative - w ecan also do this q by recursive the diffrece is only we have to find the sum by recursion.
        
        int sum_of_series = (n * (n + 1)) / 2;
        return sum_of_series * sum_of_series;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna