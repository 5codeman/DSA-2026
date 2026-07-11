class Solution {
    public:
    vector<vector<int>> cordinates = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, 1}, {-2, -1}, {2, -1}, {2, 1}};
    int checkMinStep(int x, int y, int x1, int y1, int n, vector<vector<int>>& visited) {
        queue<pair<int,int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        int steps = 0;
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                pair<int, int> pr = q.front();
                q.pop();
                int new_x = pr.first;
                int new_y = pr.second;
                if(new_x == x1 && new_y == y1) return steps;
                
                for(int itr = 0; itr <= 7; itr++) {
                    int nbr_x = new_x + cordinates[itr][0];
                    int nbr_y = new_y + cordinates[itr][1];
                    if((nbr_x >= 0 && nbr_x <= n - 1) && (nbr_y >= 0 && nbr_y <= n - 1) && visited[nbr_x][nbr_y] == 0) {
                        visited[nbr_x][nbr_y] = 1;
                        q.push({nbr_x, nbr_y});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int x = n - knightPos[1];
        int y = knightPos[0] - 1;
        int x1 = n - targetPos[1];
        int y1 = targetPos[0] - 1;
        vector<vector<int>>visited(n, vector<int>(n, 0));
        return checkMinStep(x, y, x1, y1, n, visited);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna