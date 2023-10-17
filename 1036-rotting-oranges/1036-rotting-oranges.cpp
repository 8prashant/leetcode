class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }

            }
        }
        while(!q.empty()){
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x-1>=0 && y>=0&& grid[x-1][y]==1){
                    grid[x-1][y]++;
                    q.push({x-1,y});
                }
                if(x>=0 && y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]++;
                    q.push({x,y-1});
                }
                if(x+1<=grid.size()-1 && y<=grid[0].size()-1 && grid[x+1][y]==1){
                    grid[x+1][y]++;
                    q.push({x+1,y});
                }
                if(x<=grid.size()-1 && y+1<=grid[0].size()-1 && grid[x][y+1]==1){
                    grid[x][y+1]++;
                    q.push({x,y+1});
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }

            }
        }
        return ans==0?ans:ans-1;
    }
};