class Solution {
public:
    void minChange(unordered_map<int, vector<pair<int, int>>>&graph, int src,  vector<int>& visited, int& count) {
        visited[src] = 1;

        for(const auto& itr : graph[src]) {
            if(itr.second == 1 && visited[itr.first] == 0) {
                // int count = 
                minChange(graph, itr.first, visited, count += 1);
                // return count += 1;
            }
            else if(itr.second == 0 && visited[itr.first] == 0) {
                // int count = 
                minChange(graph, itr.first, visited, count);
                // return count;
            }
        }
        // return 0;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>>graph;
        vector<int> visited(n, 0);
        int count = 0;
        for(const auto& itr : connections) {
            int i = itr[0];
            int j = itr[1];
            graph[i].push_back({j, 1});
            graph[j].push_back({i, 0});
        }
        minChange(graph, 0, visited, count);
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna