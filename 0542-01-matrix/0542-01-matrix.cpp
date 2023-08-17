class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, -1)); // Initialize distances with -1
        queue<pair<int, int>> q; // Queue for BFS
        
        // Initialize the queue and distances for cells with value 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Define possible directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int newRow = current.first + dir.first;
                int newCol = current.second + dir.second;
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] = dist[current.first][current.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        return dist;
    }
};
