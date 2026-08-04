class Solution {
public:
    bool helper(int src, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, vector<int>& output) {
        visited[src] = 1;
        path[src] = 1;
        bool flag = true;
        for(const auto& itr : graph[src]) {
            if(!visited[itr]) {
                bool check = helper(itr, graph, visited, path, output);

                if(check) output[itr] = 1;
                else flag = false;
            }

            else if(visited[itr] && path[itr]) flag =  false;

            else if(visited[itr] && !output[itr]) flag = false;
        }
        path[src] = 0;
        return flag;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);
        vector<int>path(n, 0);
        vector<int>output(n , 0);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bool check = helper(i, graph, visited, path, output);
                if(check) output[i] = 1;
            }
        }
        vector<int>safeNode;
        for(int i = 0; i < output.size(); i++) {
            if(output[i] == 1) safeNode.push_back(i);
        }
        return safeNode;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna