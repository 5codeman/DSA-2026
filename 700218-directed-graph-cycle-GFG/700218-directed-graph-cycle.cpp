class Solution {
  public:
    bool DFS(int src, unordered_map<int, vector<int>>&graph, vector<int>&visited, unordered_set<int>&path) {
        visited[src] = 1;
        path.insert(src);
        for(const auto& itr : graph[src]) {
            if(!visited[itr]) {
                bool check = DFS(itr, graph, visited, path);
                if(check) return true;
                else path.erase(itr);
            }
            else if(path.find(itr) != path.end()) return true;
        }
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>>graph;
        vector<int>visited(V, 0);
        unordered_set<int>path;
        for(const auto& itr : edges) {
            int u = itr[0];
            int v = itr[1];
            graph[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool ans = DFS(i, graph, visited, path);
                if(ans) return true;
                else path.erase(i); // Bcz in upper function it marked as visted and due to BT i marked as unvsited 
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna