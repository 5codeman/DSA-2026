class Solution {
public:
    int helper(int src, vector<int>& edges, vector<int>& visited, vector<int>& path, int nodeCount) {
        if(visited[src] && !path[src]) return -1;

        visited[src] = 1;
        path[src] = nodeCount;
        int count = -1;

        if(edges[src] != -1 && !path[edges[src]]) {
            count = helper(edges[src], edges, visited, path, nodeCount + 1);
        }

        else if(edges[src] != -1 && path[edges[src]]) {
            count = (path[src] - path[edges[src]]) + 1;
        }
        path[src] = 0;
        return count;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> path(n, 0);
        int longestCycle = -1;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int ans = helper(i, edges, visited, path, 1);
                longestCycle = max(longestCycle, ans);
            }
        }
        return longestCycle;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna