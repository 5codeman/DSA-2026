class Solution {
public:
    bool checkPathByBFS(auto graph, int source, int destination, int size) {
        queue<int>qu;
        vector<int>visited(size + 1);
        visited[source] = 1;
        qu.push(source);
        while(!qu.empty()) {
            int node = qu.front();
            if(node == destination) return true;
            qu.pop();
            for(const auto& i : graph[node]) {
                if(visited[i] != 1) {
                    visited[i] = 1;
                    qu.push(i);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>graph;

        for(int i = 0; i < edges.size(); i++) {
            int vertex1 = edges[i][0];
            int vertex2 = edges[i][1];
            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }

        return checkPathByBFS(graph, source, destination, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna