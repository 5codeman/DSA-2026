class Solution {
  public:
    bool helper(int src, unordered_map<int, vector<int>>&adj, vector<int>&visited, int parentVertex) {
        visited[src] = 1;
        for(const auto& itr : adj[src]) {
            if(!visited[itr]) {
                bool ans = helper(itr, adj, visited, src);
                if(ans == true) return true;
            }
            else if(visited[itr] && itr != parentVertex) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>>adj;
        vector<int>visited(V, 0);
        for(const auto& itr : edges) {
            int u = itr[0];
            int v = itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool ans = helper(i, adj, visited, -1);
                if(ans == true) return true;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna