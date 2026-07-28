class Solution {
  public:
    bool helper(int src, unordered_map<int, vector<int>>& graph, vector<int>& visited, vector<int>& safeNode, vector<int>& path) {
        visited[src] = 1;
        path[src] = 1;
        bool flag = true;
        for(const auto& itr : graph[src]) {
            if(!visited[itr]) {
                bool ans = helper(itr, graph, visited, safeNode, path);
                if(ans == false) flag = false;
            
                else if(ans = true) safeNode[itr] = itr;
            }
            else if(path[itr]) flag = false;
            
            else if(visited[itr] && safeNode[itr] == -1) flag = false;
        }
        path[src] = 0;
        return flag;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> safeNode(V, -1);
        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        unordered_map<int, vector<int>> graph;
        
        for(const auto& itr : edges) {
            int u = itr[0];
            int v = itr[1];
            graph[u].push_back(v);
        }
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool temp = helper(i, graph, visited, safeNode, path);
                if(temp == true) {
                    safeNode[i] = i;
                }
            }
        }
        
        vector<int> output;
        for(const auto& itr : safeNode) {
            if(itr != -1) output.push_back(itr);
        }
        return output;
        
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna