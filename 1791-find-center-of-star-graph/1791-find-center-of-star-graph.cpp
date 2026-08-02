class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // we an find it by making adjancy list
        // but for this I am doing it by just small thinking and trick.

        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        else return edges[0][1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna