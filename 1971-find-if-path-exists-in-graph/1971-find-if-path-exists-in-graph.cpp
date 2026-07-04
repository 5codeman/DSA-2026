class Solution {
public:
    // bool checkPathByBFS(auto& graph, int source, int destination, int size) {
    //     queue<int>qu;
    //     vector<int>visited(size, 0);
    //     visited[source] = 1;
    //     qu.push(source);
    //     while(!qu.empty()) {
    //         int node = qu.front();
    //         if(node == destination) return true;
    //         qu.pop();
    //         for(const auto& i : graph[node]) {
    //             if(visited[i] != 1) {
    //                 visited[i] = 1;
    //                 qu.push(i);
    //             }
    //         }
    //     }
    //     return false;
    // }

    bool checkPathByDFS(auto& graph, int source, int destination, int size, auto& visited) {
        
        visited[source] = 1;

        if(source == destination) return true;

        for(const auto& i : graph[source]) {
            if(visited[i] == 0) {
                // visited[i] = 1; - ye repeted karne ka koi faida nahi hai kyunki recursive approach hai and bahar mai same kaam to ho hi raha hai.
                auto check = checkPathByDFS(graph, i, destination, size, visited);
                if(check == true) return true;
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>graph;
        vector<int>visited(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            int vertex1 = edges[i][0];
            int vertex2 = edges[i][1];
            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }

        return checkPathByDFS(graph, source, destination, n, visited);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna