class Solution {
  public:
    bool BFS(int src, unordered_map<int, vector<int>>&graph, vector<int>&visited, vector<int>&parent) {
        queue<int>qu;
        visited[src] = 1;
        qu.push(src);
        while(!qu.empty()) {
            int vertex = qu.front();
            qu.pop();
            for(const auto& itr : graph[vertex]) {
                if(!visited[itr]) {
                    qu.push(itr);
                    visited[itr] = 1;
                    parent[itr] = vertex;
                }
                else if(visited[itr] && parent[vertex] != itr) {
                    return true;
                }
                
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>>graph;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>visited(V, 0);
        vector<int>parent(V, -1);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool check = BFS(i, graph, visited, parent);
                if(check == true) return true;
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna